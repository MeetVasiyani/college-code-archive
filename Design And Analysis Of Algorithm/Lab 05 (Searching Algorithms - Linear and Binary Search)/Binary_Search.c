#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000

int binarySearch(int arr[],int n,int target){
    int mid,left = 0,right = n-1;
    while(left <= right){
        mid = left + (right - left)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
}

int readArrayFromFile(const char *filename,int arr[], int n){
    FILE *fp = fopen(filename,"r");

    if(!fp){
        printf("Cannot open file %s\n",filename);
        return 0;
    }

    for (int i = 0; i < n; i++){
        fscanf(fp,"%d",&arr[i]);
    }
    fclose(fp);
    return 1;
    
}

void main(){
    int arr[N],temp;
    clock_t start,end;
    double time_take;

    readArrayFromFile("D:\\Semester 5\\DAA(Design and Analysis of Algorithm)\\programs\\Arrays\\best_case_100000.txt",arr,N);

    printf("Enter element to be searched : ");
    scanf("%d",&temp);
    printf("Searching array using Binary Search...\n");
    start = clock();
    int index = binarySearch(arr, N, temp);
    printf("Element found at index : %d\n",index);
    end = clock();

    time_take = ((double)(end - start))/CLOCKS_PER_SEC * 1000;
    printf("Time taken to Search the array: %lf ms\n", time_take);
    
}