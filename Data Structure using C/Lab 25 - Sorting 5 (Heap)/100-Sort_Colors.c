/*100. Given an array nums with n objects colored red, white, or blue, sort them in
place so that objects of the same color are adjacent, with the colors in the order 
red, white, and blue. We will use the integers 0, 1, and 2 to represent the color 
red, white, and blue, respectively. 
Sample Example-1: 
Input: nums = [2,0,2,1,1,0]    
Output: [0,0,1,1,2,2] 
Sample Example-2: 
Input: nums = [2,0,1]    
Output: [0,1,2]
*/

#include <stdio.h>

void main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Dutch National Flag Algorithm
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }

    printf("Array after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}