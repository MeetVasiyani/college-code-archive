#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000

void generateBestTestCase(int arr[], int i, int j){
    if(i >= j) return;
    int mid = (i + j) / 2;

    int temp = arr[i];
    arr[i] = arr[mid];
    arr[mid] = temp;

    generateBestTestCase(arr, i+1, mid);
    generateBestTestCase(arr, mid + 1, j);
}

int sort(int arr[], int start, int end) {
    int pivot = arr[start];
    int left = start + 1;
    int right = end;

    while (left <= right) {
        while (left <= end && arr[left] <= pivot) left++;
        while (right > start && arr[right] > pivot) right--;

        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    int temp = arr[start];
    arr[start] = arr[right];
    arr[right] = temp;

    return right;
}

void quickSort(int arr[],int start, int end){
    if(start < end){
        int pivot = sort(arr,start,end);
        quickSort(arr,start,pivot-1);
        quickSort(arr,pivot+1,end);
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

    printf("Sorting array using Quick Sort...\n");
    start = clock();
    quickSort(arr, 0, N - 1);   
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