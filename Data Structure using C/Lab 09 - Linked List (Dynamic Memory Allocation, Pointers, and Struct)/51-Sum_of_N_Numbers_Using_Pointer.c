/*51. WAP to calculate the sum of n numbers using Pointer.*/

#include <stdio.h>

void main(){

	int n, i, sum = 0;
	int *ptr;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int arr[n];
	ptr = arr;

	printf("Enter %d elements:\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", ptr + i);
	}

	for (i = 0; i < n; i++) {
		sum += *(ptr + i);
	}

	printf("Sum of the elements: %d\n", sum);
}