import java.util.*;

class Main {
    public static void merge(int[] arr,int start,int mid ,int end){
        int[] temp = new int[end-start+1];
        int left = start,right = mid+1,index = 0;

        while(left <= mid && right <= end){
            if(arr[left] < arr[right]){
                temp[index++] = arr[left++];
            }
            else{
                temp[index++] = arr[right++];
            }
        }

        while(left <= mid){
            temp[index++] = arr[left++];
        }

        while(right <= end){
            temp[index++] = arr[right++];    
        }

        index = 0;
        while(start <= end){
            arr[start++] = temp[index++];
        }
    }
    public static void mergeSort(int[] arr,int start,int end){

        if(start >= end) return;

        int mid = (start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,start,mid,end);
    }
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of array : ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        for(int i = 0; i < n; i++){
            System.out.println("Enter number for index " + (i+1) + " : ");
            arr[i] = sc.nextInt();
        }

        mergeSort(arr,0,n-1);

        System.out.println("Array : ");
        
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+", ");
        }
    }
}

