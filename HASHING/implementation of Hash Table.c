#include<stdio.h>
#include<stdlib.h>

typedef struct st{
	int Key;
	int data;
}Table;

Table *arr;
int size=5;

int hashFunction(int key){
	return (key % size);
}

int checkPrime(int n){
    int i;
    if(n==1 || n==0){
        return 0;
    }
    for (i = 2; i < n / 2; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int getPrime(int n){
    if(n % 2 == 0){
        n++;
    }
    while (!checkPrime(n)){
        n += 2;
    }
    return n;
}

void init_array(){
	int i;
    size = getPrime(size);
    arr = (Table*)malloc(size * sizeof(Table));
    for (i = 0; i < size; i++){
        arr[i].Key = 0;
        arr[i].data = 0;
    }
}

void add(int key,int value){
	int index=hashFunction(key);
	if(arr[index].data==0){
		arr[index].Key=key;
		arr[index].data=value;
		printf("Key %d Inserted!!\n", key);
	}
	else if(arr[index].Key==key){
		arr[index].data=value;
	}
	else{
		printf("\n\n!!@@!!COLLISSION!!@@!!\n\n");
	}
}

void remove_value(int key){
	int index=key%size;
	if(arr[index].data==0){
		printf("The Key does not exist\n");
	}
	else{
		arr[index].Key=0;
		arr[index].data=0;
		printf("Key %d Removed!!\n",key);
	}
}
int size_of_hash_table(){
	return size;
}

void display(){
    int i;
    for (i = 0; i < size; i++){
        if (arr[i].data == 0){
            printf("\n arr[%d]: //EMPTY// ", i);
        }
        else{
            printf("\n key: %d arr[%d]: %d \t", arr[i].Key, i, arr[i].data);
        }
    }
}
int main(){
    int choose, key, data, n;
    char choice;
    init_array();
    do{
        printf("1.Insert item in the Hash Table\n2.Remove item from the Hash Table\n3.Check the size of Hash Table\n4.Display a Hash Table\n\nPlease enter your choice: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Enter key :\t");
                scanf("%d", &key);
                printf("Enter data :\t");
                scanf("%d", &data);
                add(key, data);
                break;
                case 2:
                    printf("Enter the key to delete: ");
                    scanf("%d", &key);
                    remove_value(key);
                    break;
                    case 3:
                    	n = size_of_hash_table();
                        printf("Size of Hash Table is:: %d\n", n);
                        break;
                        case 4:
                        	printf("\n HASH TABLE::\n");
                            display();
                            break;
                            default:
                                break;
        }
        printf("\nDo you want to continue? y/n?: ");
        scanf(" %c", &choice);
    }while(choice=='y' || choice=='Y');
    return 0;
}
