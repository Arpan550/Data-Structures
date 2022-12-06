#include<stdio.h>
#include<stdlib.h>

typedef struct st1{
	double ch;
	double b;
	double info;
}Node1;

typedef struct st2{
	char ch;
	double info;
}Node2;

Node1 *start1 =NULL;
Node2 *start2 =NULL;

int main(){
	Node1 ptr1;
	Node2 ptr2;
	printf("Size of the Node1 Structure::  %d\n", sizeof(ptr1));
	printf("Size of the Node2 Structure::  %d\n", sizeof(ptr2));
	printf("\nIn Node1 Structure::  ");
	if(sizeof(ptr1)>(sizeof(ptr1.b)+sizeof(ptr1.ch)+sizeof(ptr1.info))){
		printf("There are Slack Bytes..\n");
	}
	else{
		printf("There are no Slack Bytes..\n");
	}
	printf("\nIn Node2 Structure::  ");
	if(sizeof(ptr2)>(sizeof(ptr2.ch)+sizeof(ptr2.info))){
		printf("There are Slack Bytes..\n");
	}
	else{
		printf("There are no Slack Bytes..\n");
	}
	return 0;
}
