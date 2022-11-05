//Fibonacci Numbers
#include<stdio.h>

int fibonacci(int n){
	if(n==0 || n==1){
		return n;
	}
	else{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}

int main(){
	int terms,i;
	printf("No. of terms: ");
	scanf("%d", &terms);
	printf("Fibonacci series upto %d terms:: ", terms);
	for(i=0;i<terms;i++){
	    printf("%d  ", fibonacci(i));  	
	}
	return 0;
}
