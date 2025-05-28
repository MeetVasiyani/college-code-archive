/*93. Write a program to implement Insertion Sort using Array. */

#include <stdio.h>

void main(){

	int arr[10], i, j, temp, n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter the elements: ");
	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	for (i = 1; i < n; i++){
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
	printf("Sorted array: ");
	for (i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}