import java.util.*;

class Main {

    public static void Heapify(int[] arr,int index,int n){
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
            int temp = arr[largest];
            arr[largest] = arr[index];
            arr[index] = temp;
            Heapify(arr,largest,n);
        }
    }
    public static void BuildMaxHeap(int[] arr,int n){
        for(int i = n/2 - 1; i >= 0; i--){
            Heapify(arr,i,n);
        }
    }
    public static void sortArray(int[] arr,int n){
        for(int i = n-1; i > 0; i--){
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            Heapify(arr,0,i);
        }
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

        BuildMaxHeap(arr,n);
        sortArray(arr,n);
        System.out.println("Array : ");
        
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+", ");
        }
    }
}

