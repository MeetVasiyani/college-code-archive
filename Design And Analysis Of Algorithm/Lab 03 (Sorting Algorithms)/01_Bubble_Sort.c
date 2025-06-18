#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000

void bubbleSort(int arr[],int n){
    for(int i = 0; i < n-1; i++){
        int swapped = 0;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
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
    int arr[N];
    clock_t start,end;
    double time_take;

    readArrayFromFile("D:\\Semester 5\\DAA(Design and Analysis of Algorithm)\\programs\\Arrays\\worst_case_100000.txt",arr,N);

    printf("Sorting array using Bubble Sort...\n");
    start = clock();
    bubbleSort(arr, N);
    end = clock();

    time_take = ((double)(end - start))/CLOCKS_PER_SEC * 1000;
    printf("Time taken to sort the array: %lf ms\n", time_take);
    
}