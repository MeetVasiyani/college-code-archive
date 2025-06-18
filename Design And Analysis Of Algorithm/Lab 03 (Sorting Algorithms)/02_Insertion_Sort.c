#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000

void insertionSort(int arr[],int n){
    int i = 1, j, key;

    while (i < n) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        i++;
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

    readArrayFromFile("D:\\Semester 5\\DAA(Design and Analysis of Algorithm)\\programs\\Arrays\\worst_case_100000.txt",arr,N);

    printf("Sorting array using Bubble Sort...\n");
    start = clock();
    insertionSort(arr, N);
    end = clock();

    time_take = ((double)(end - start))/CLOCKS_PER_SEC * 1000;
    printf("Time taken to sort the array: %lf ms\n", time_take);
    
}