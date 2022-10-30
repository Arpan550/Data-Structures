//CLL by DLL
//CLL by SLL
#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
	struct st *lptr;
    int info;
    struct st *rptr;

}Node;
Node *start = NULL;

// inserting node at the begining
void add_beg(int val)
{
    Node *newptr=NULL, *ptr;
    newptr=(Node*)malloc(sizeof(Node));
    newptr->info=val;
    newptr->lptr=newptr->rptr=NULL;
    if(start==NULL)
    {
        start = newptr;
        start->rptr = newptr;
        start->lptr=newptr;
    }
    else
    {
        ptr = start;
        while (ptr->rptr != start)
        {
            ptr=ptr->rptr;
        }

        newptr->rptr = start;
        newptr->lptr=ptr;
        start = newptr;
        ptr->rptr = start;
    }
}
// inserting node at end
void add_end(int val)
{
    Node *newptr=NULL, *ptr;
    newptr=(Node*)malloc(sizeof(Node));
    newptr->info=val;
    newptr->lptr=newptr->rptr=NULL;
    if(start == NULL)
    {
        start = newptr;
        start->rptr = newptr;
        start->lptr=newptr;
    }
    else
    {
        ptr = start;
        while (ptr->rptr!= start)
        {
            ptr=ptr->rptr;
        }
        newptr->rptr = start;
        ptr->rptr = newptr;
        newptr->lptr=ptr;
        start->lptr=newptr;
    }
}
// inserting node at any position
void add_anypos(int val, int pos)
{
    Node *newptr=NULL, *ptr=start;
    int steps=1;
    newptr=(Node*)malloc(sizeof(Node));
    newptr->info=val;
    newptr->rptr=newptr->lptr=NULL;
    if (start == NULL)
    {
        start = newptr;
        start->rptr=newptr;
        start->lptr=newptr;
    }
    else
    {
        while(steps<pos-1){
    	    ptr=ptr->rptr;
    	    steps++;
    	}
        newptr->rptr = ptr->rptr;
        (ptr->rptr)->lptr=newptr;
        newptr->lptr=ptr;
        ptr->rptr=newptr;
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
        if(ptr->rptr == start)
        {
            free(ptr);
            start = NULL;
        }
        else
        {
            while (ptr->rptr != start)
            {
                ptr=ptr->rptr;
            }
            start = start->rptr;
            ptr->rptr = start;
            start->lptr=ptr;
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
        if (ptr->rptr==start){
            free(ptr);
            start=NULL;
        }
        else{
            while (ptr->rptr!=start){
                newptr= ptr;
                ptr=ptr->rptr;
            }
            newptr->rptr = ptr->rptr;
            start->lptr=newptr;
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
    	if(pptr->rptr == start){
            free(pptr);
            start = NULL;
        }
        else{
			printf("Enter position: ");
	        scanf("%d", &pos);
	        while(steps<pos-1){
		        pptr=pptr->rptr;
		        steps++;
	        }
	        nptr=pptr->rptr;
	        (nptr->rptr)->lptr=pptr;
	        pptr->rptr=nptr->rptr;
	        free(nptr);        	
		}
	}
}

void display(){
	Node *ptr=start;
	while(ptr->rptr!=start){
		printf("%d<->", ptr->info);
		ptr=ptr->rptr;
	}
	printf("%d<->...<->\n", ptr->info);
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
