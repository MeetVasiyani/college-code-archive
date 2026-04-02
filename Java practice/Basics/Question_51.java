import java.util.*;

class Main {
    public static int partition(int[] arr,int start,int end){
        int pivot = arr[end];
        int i = start-1;
        for(int j = start; j < end; j++){
            if(arr[j] <= pivot){
                i++;
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }

        int temp = arr[i+1];
        arr[i+1] = pivot;
        arr[end] = temp;

        return i+1;
    }
    public static void quickSort(int[] arr,int start,int end){
        if (start >= end) return;
        int pivotIndex = partition(arr,start,end);
        quickSort(arr,start,pivotIndex-1);
        quickSort(arr,pivotIndex+1,end);
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

        quickSort(arr,0,n-1);

        System.out.println("Array : ");
        
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+", ");
        }
    }
}

