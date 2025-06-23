#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000

void Heapify(int arr [],int index,int n){
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != index){
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        Heapify(arr,largest,n);
    }
}

void BuildMaxHeap(int arr [],int n){
    for(int i = (n/2)-1; i >= 0; i--){
        Heapify(arr,i,n);
    }
}

void sortArray(int arr[],int n){
    for(int i = n-1; i >= 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        Heapify(arr,0,i);
    }
}

void readArrayFromFile(const char *filename,int arr[],int n){
    FILE *fp = fopen(filename,"r");

    if(!fp){
        printf("Cannot open file %s\n",filename);
        return;
    }

    for(int i = 0; i < n; i++){
        fscanf(fp,"%d",&arr[i]);
    }
    fclose(fp);
}

void main(){
    int arr[N];
    clock_t start,end;
    double time_taken;

    readArrayFromFile("D:\\Semester 5\\DAA(Design and Analysis of Algorithm)\\programs\\Arrays\\average_case_100000.txt",arr,N);

    start = clock();
    BuildMaxHeap(arr,N);
    sortArray(arr,N);
    end = clock();

    time_taken = ((double)(end - start))/CLOCKS_PER_SEC * 1000;
    printf("Time taken to sort the array: %lf ms\n", time_taken);

}