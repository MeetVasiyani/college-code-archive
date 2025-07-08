#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100

int sort(int arr[],int start,int end){
    int pivot = start;
    int left = start+1, right = end;
    while(left <= right){
        while(arr[pivot] >= arr[left] && left < end){
            left++;
        }
        while(arr[pivot] < arr[right] && right > start){
            right--;
        }
        if(left < right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    int temp = arr[pivot];
    arr[pivot] = arr[right];
    arr[right] = temp;
    return pivot;
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

    readArrayFromFile("D:\\Semester 5\\DAA(Design and Analysis of Algorithm)\\programs\\Arrays\\worst_case_100.txt",arr,N);

    printf("Sorting array using Quick Sort...\n");
    start = clock();
    quickSort(arr, 0,N);   
    end = clock();

    time_take = ((double)(end - start))/CLOCKS_PER_SEC * 1000;
    printf("Time taken to sort the array: %lf ms\n", time_take);
    
}