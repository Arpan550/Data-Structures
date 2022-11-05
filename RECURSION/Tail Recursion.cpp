//Tail Recursion

#include<stdio.h>

Tail_recursion(int n){
	if(n>0){
		printf("The value of n is %d\n", n);
	}
	Tail_recursion(n-1);
}
int non_tail_recursion(int n){
	if(n>0){
		non_tail_recursion(n-1);
		printf("\nNon-tail recursive call");
		non_tail_recursion(n-1);
	}
}

int main(){
	int n;
	printf("Enter: ");
	scanf("%d", &n);
	Tail_recursion(n);
	non_tail_recursion(n);
	return 0;
}
