#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000

void selectionSort(int arr[],int n){
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(arr[i] < arr[min]){
                min = i;
            }
        }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
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

    printf("Sorting array using Selection Sort...\n");
    start = clock();
    selectionSort(arr, N);
    end = clock();

    time_take = ((double)(end - start))/CLOCKS_PER_SEC * 1000;
    printf("Time taken to sort the array: %lf ms\n", time_take);
    
}