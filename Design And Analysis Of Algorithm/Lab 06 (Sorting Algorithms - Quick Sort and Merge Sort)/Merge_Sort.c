#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000

void merge(int arr[], int start, int mid,int end) {
    int temp [end-start+1];
    int count = 0;
    int left = start;
    int right = mid+1;
    while(left <= mid && right <= end){
        if(arr[left] < arr[right]){
            temp[count++] = arr[left++];
        }
        else{
            temp[count++] = arr[right++];
        }
    }

    while(left <= mid){
        temp[count++] = arr[left++];
    }

    while(right <= end){
        temp[count++] = arr[right++];
    }

    for(int i = 0; i < count; i++){
        arr[start+i] = temp[i];
    }
}

void mergeSort(int arr[],int start, int end){
    if(start < end){
        int mid = (start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
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
    int arr[N];
    clock_t start,end;
    double time_take;

    readArrayFromFile("D:\\Semester 5\\DAA(Design and Analysis of Algorithm)\\programs\\Arrays\\best_case_100000.txt",arr,N);

    printf("Sorting array using Merge Sort...\n");
    start = clock();
    mergeSort(arr, 0, N-1);   
    end = clock();

    time_take = ((double)(end - start))/CLOCKS_PER_SEC * 1000;
    printf("Time taken to sort the array: %lf ms\n", time_take);
    
    for (int i = 0; i < N - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("Array not sorted correctly!\n");
            break;
        }
    }
}