/*53. WAP to sort the array elements using Pointer. */

#include<stdio.h>

void main(){

	int arr[100], n, i, j, temp;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter the elements: \n");
	for(i=0; i<n; i++){
        printf("Element arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(*(arr+i) > *(arr+j)){
				temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
		}
	}
	printf("Sorted array: ");
	for(i=0; i<n; i++){
		printf("%d ", *(arr+i));
	}
	
}