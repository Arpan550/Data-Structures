//CLL by SLL
#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int info;
    struct st *link;

}Node;
Node *start = NULL;

// inserting node at the begining
void add_beg(int val)
{
    Node *newptr=NULL, *ptr;
    newptr=(Node*)malloc(sizeof(Node));
    newptr->info=val;
    newptr->link=NULL;
    if(start==NULL)
    {
        start = newptr;
        start->link = newptr;
    }
    else
    {
        ptr = start;
        while (ptr->link != start)
        {
            ptr=ptr->link;
        }

        newptr->link = start;
        start = newptr;
        ptr->link = start;
    }
}
// inserting node at end
void add_end(int val)
{
    Node *newptr=NULL, *ptr;
    newptr=(Node*)malloc(sizeof(Node));
    newptr->info=val;
    newptr->link=NULL;
    if(start == NULL)
    {
        start = newptr;
        start->link = newptr;
    }
    else
    {
        ptr = start;
        while (ptr->link!= start)
        {
            ptr=ptr->link;
        }
        newptr->link = start;
        ptr->link = newptr;
    }
}
// inserting node at any position
void add_anypos(int val, int pos)
{
    Node *newptr=NULL, *ptr=start;
    int steps=1;
    newptr=(Node*)malloc(sizeof(Node));
    newptr->info=val;
    newptr->link=NULL;
    if (start == NULL)
    {
        start = newptr;
        start->link = newptr;
    }
    else
    {
        while(steps<pos-1){
    	    ptr=ptr->link;
    	    steps++;
    	}
    	if(pos==1){
    		newptr->link=start;
    		start=newptr;
		}
		else{
            newptr->link = ptr->link;
            ptr->link=newptr;
        }
    }
}
// deleting node at the begining
void delete_beg()
{
    if (start == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        Node *ptr = start;
        if(ptr->link == start)
        {
            free(ptr);
            start = NULL;
        }
        else
        {
            while (ptr->link != start)
            {
                ptr=ptr->link;
            }
            start = start->link;
            ptr->link = start;
        }
    }
}

// deleting from the end
void delete_end()
{
    Node *ptr = start, *newptr;
    if(start == NULL)
    {
        printf("list is empty\n");
    }
    else{
        if (ptr->link==start){
            free(ptr);
            start=NULL;
        }
        else{
            while (ptr->link!=start){
                newptr= ptr;
                ptr=ptr->link;
            }
            newptr->link = ptr->link;
            free(ptr);
        }
    } 
}
//delete at any position
void delete_anypos(){
	int steps=1, pos;
	Node *pptr=start, *nptr;
	if (start == NULL)
    {
        printf("list is empty\n");
    }
    else{
    	if(pptr->link == start){
            free(pptr);
            start = NULL;
        }
        else{
			printf("Enter position: ");
	        scanf("%d", &pos);
	        while(steps<pos-1){
		        pptr=pptr->link;
		        steps++;
	        }
	        nptr=pptr->link;
	        pptr->link=nptr->link;
	        free(nptr);        	
		}
	}
}

void display(){
	Node *ptr=start;
	while(ptr->link!=start){
		printf("%d->", ptr->info);
		ptr=ptr->link;
	}
	printf("%d->...->\n", ptr->info);
}

int main(){
	char choice;
	int num, choose, pos;
	while(1){
		printf("Do you want to Enter? y/n? ");
		scanf(" %c", &choice);
		if(choice=='y' || choice=='Y'){
			printf("Enter where you want to add:\n1. At the end\n2. At beggining\n3. At any position\n");
            scanf("%d", &choose);
            switch(choose){
            	case 1:
            		printf("Enter num to add: ");
			        scanf("%d", &num);
			        add_end(num);
			        fflush(stdin);
			        break;
			        case 2:
			        	printf("Enter num to add: ");
			            scanf("%d", &num);
			            add_beg(num);
			            fflush(stdin);
			            break;
			            case 3:
			            	printf("Enter position: ");
			            	scanf("%d", &pos);
			            	printf("Enter num: ");
			            	scanf("%d", &num);
			            	add_anypos(num, pos);
			            	fflush(stdin);
			            	break;
			            	default:
			            		break;
			}
		}
		else{
			break;
		}
	printf("\nLINKED LIST:\t");
	display();
	}
	printf("\nLINKED LIST:\t");
	display();
	
	
	while(1){
		printf("\n\nDo you want to Delete? y/n? ");
		scanf(" %c", &choice);
		if(choice=='y' || choice=='Y'){
			printf("Enter where you want to delete:\n1. At the end\n2. At beggining\n3. At any position\n");
            scanf("%d", &choose);
            switch(choose){
            	case 1:
            		delete_end();
            		fflush(stdin);
			        break;
			        case 2:
			        	delete_beg();
			        	fflush(stdin);
			            break;
			            case 3:
			                delete_anypos();
			                fflush(stdin);
			            	break;
			            	default:
			            		break;
			}
		}
		else{
			break;
		}
	printf("\nNow, LINKED LIST:\t");
	display();
	}
	printf("\nNow, LINKED LIST:\t");
	display();
	
	return 0;
}
