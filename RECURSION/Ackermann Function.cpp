//Ackermann Function
//It is a function with two arguments each of which can be assigned any non-negative integer.
/*Ackermann Function:: A(m,n)
       1. if m=0, then A(m,n)=n+1
       2. if m!=0, but n=0, then A(m,n)=A(m-1,1)
       3. if m & n !=0, A(m,n)=A(m-1, A(m,n-1))*/
       
#include<stdio.h>

int ackermann(int m,int n){
	if(m==0){
		return n+1;
	}
	else if(m>0 && n==0){
		return ackermann(m-1,1);
	}
	else{
		return ackermann(m-1, ackermann(m,n-1));
	}
}
int main(){
	int m,n;
	printf("Enter the respective variables in Ackerman Function A(m,n):\n");
	scanf("%d %d", &m, &n);
	printf("So, m=%d & n=%d",m,n);
	printf("\nAckermann(%d,%d): %d",m,n, ackermann(m,n));
	return 0;
}
