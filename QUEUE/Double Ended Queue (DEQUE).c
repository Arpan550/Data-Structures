#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int queue[MAX];
int front = -1;
int rear = -1;

void add_rear(int value){
	if((front==0 && rear==MAX-1) || (front==rear+1)){
		printf("Queue Overflow!!\n");
		exit(1);
		getchar();
	}
	else{
	    if(rear==-1 && front==-1){
		    rear=front=0;
		    queue[rear]=value;
	    }
	    else if(rear==MAX-1){
		    rear=0;
		    queue[rear]=value;
	    }
	    else{
		    rear++;
		    queue[rear]=value;
	    }
    }
}

void add_front(int value){	
    if((front==0 && rear==MAX-1) || (front==rear+1)){
		printf("Queue Overflow!!\n");
		exit(1);
		getchar();
	}
	else {
	    if(rear==-1 && front==-1){
		    rear=front=0;
		    queue[front]=value;
	    }
	    else if(front==0){
		    front=MAX-1;
		    queue[front]=value;
	    }
	    else{
		    front--;
		    queue[front]=value;
	    }
    }  
}

void delete_front(){
	if(front==-1 && rear==-1){
		printf("Queue is EMPTY!!\n");
		exit(1);
		getchar();
	}
	else if(rear==front){
	    rear=front=-1;
	}
	else{
		if(front==MAX-1){
			front=0;
		}
		else{
			printf("Deleted element: %d\n", queue[front]);
		    front++;
		}
	}
}

void delete_rear(){
	if(front==-1 && rear==-1){
		printf("Queue is EMPTY!!\n");
		exit(1);
		getchar();
	}
	else if(rear==front){
	    rear=front=-1;
	}
	else{
		if(rear==0){
			rear=MAX-1;
		}
		else{
			printf("Deleted element: %d\n", queue[rear]);
		    rear--;
		}
	}
}

void display(){
	int front_pos = front,rear_pos = rear;
	if(front == -1)
	{	printf("Queue is empty\n");
		return;	 }
	printf("FRONT END ::  ");
	if( front_pos <= rear_pos )
	{	while(front_pos <= rear_pos)
		{	printf("%d ",queue[front_pos]);
			front_pos++;	}	}
	else
	{	while(front_pos <= MAX-1)
		{	printf("%d ",queue[front_pos]);
			front_pos++;	}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{	printf("%d ",queue[front_pos]);
			front_pos++;
		}
	}
	printf(" :: REAR END\n");
}

void input_restricted_queue(){
	int choice,num;
	while(1){
		printf("\n1.Insert from Rear end\n2.Delete from Rear end\n3.Delete from Front end\n4.Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter num to add: ");
		        scanf("%d", &num);
	            add_rear(num);
	            fflush(stdin);
	            break;
	            case 2:
	            	delete_rear();
	            	fflush(stdin);
	            	break;
	            	case 3:
	            		delete_front();
	            		fflush(stdin);
	            		break;
	            		case 4:
	            			exit(1);
	            			getchar();
	            			break;
	            			default:
	            				break;
		}
		printf("\nDEQUE::  ");
		display();
	}
	printf("\nDEQUE::  ");
	display();
}

void output_restricted_queue(){	
    int choice,num;
	while(1){
		printf("\n1.Insert from Rear end\n2.Insert from Front end\n3.Delete from Front end\n4.Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter num to add: ");
		        scanf("%d", &num);
	            add_rear(num);
	            fflush(stdin);
	            break;
	            case 2:
	            	printf("\nEnter num to add: ");
                    scanf("%d", &num);
	                add_front(num);
	            	fflush(stdin);
	            	break;
	            	case 3:
	            		delete_front();
	            		fflush(stdin);
	            		break;
	            		case 4:
	            			exit(1);
	            			getchar();
	            			break;
	            			default:
	            				break;
		}
		printf("\nDEQUE::  ");
		display();
	}
	printf("\nDEQUE::  ");
	display();
}

int main(){	
    int choice;
	printf("1.Input restricted dequeue\n");
	printf("2.Output restricted dequeue\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
	 case 1 :
		input_restricted_queue();
		break;
	 case 2:
		output_restricted_queue();
		break;
	 default:
		break;
	}
	return 0;
}

