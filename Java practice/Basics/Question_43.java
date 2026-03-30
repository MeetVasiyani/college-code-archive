import java.util.*;

class Main {
    public static void bubbleSort(int[] arr){
        int n = arr.length;
        for(int i = 0; i < n - 1; i++){
            boolean flag = true;
            for(int j = 1; j < n - i; j++){
                if(arr[j-1] > arr[j]){
                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                    flag = false;
                }
            }
            if (flag) break;
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

        bubbleSort(arr);

        System.out.println("Array : ");
        
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+", ");
        }
    }
}

