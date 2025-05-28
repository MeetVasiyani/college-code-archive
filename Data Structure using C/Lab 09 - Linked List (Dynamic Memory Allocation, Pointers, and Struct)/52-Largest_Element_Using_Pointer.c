/*52. WAP to find the largest element in the array using Pointer.*/

#include <stdio.h>

void main(){

	int arr[50], i, n, largest;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("Enter the elements of the array: ");
	for (i = 0; i < n; i++)
	{
        printf("Element %d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	largest = *arr;
	for (i = 1; i < n; i++)
	{
		if (*(arr + i) > largest)
		{
			largest = *(arr + i);
		}
	}
	printf("The largest element in the array is: %d", largest);
	
}