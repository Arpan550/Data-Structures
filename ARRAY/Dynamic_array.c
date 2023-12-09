#include<stdio.h>
#include<stdlib.h>

struct array{
 int *A;
 int size;
 int length;
};
struct array arr;
int main(){
	int n,i;
	printf("Enter the size of the array: ");
	scanf("%d",&arr.size);
	arr.A=(int *)malloc(arr.size*sizeof(int));
	printf("Enter the no of elements in the array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d", &arr.A[i]);
		arr.length=n;
	}
	printf("Elements are: \n");
	for(i=0;i<n;i++){
		printf("%d ", arr.A[i]);
	}
	return 0;
}
