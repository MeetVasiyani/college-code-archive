/*50. WAP to get and print the array elements using Pointer. */

#include<stdio.h>

void main(){

	int arr[5], i;
	int *ptr;

	printf("Enter 5 elements:\n");
	for(i=0; i<5; i++){
		scanf("%d", &arr[i]);
	}

	ptr = arr;

	printf("Elements of the array are:\n");
	for(i=0; i<5; i++){
		printf("%d ", *(ptr + i));
	}
	
}