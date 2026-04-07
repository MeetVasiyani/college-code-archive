import java.util.*;

class Main {
    public static void countingSort(int[] arr,int max){
        int n = arr.length;
        if(n == 0){
            System.out.println("Array is empty.");
            return;
        }
        int [] temp = new int[max+1];
        int [] result = new int[n];

        for(int i = 0; i < n; i++){
            temp[arr[i]]++;
        }

        for(int i = 1; i < temp.length; i++){
            temp[i] = temp[i] + temp[i-1];
        }

        for(int i = n-1; i >= 0; i--){
            result[temp[arr[i]] - 1] = arr[i];
            temp[arr[i]]--;
        }
        for(int i = 0; i < n; i++){
            arr[i] = result[i];
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

        int max = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] > max) max = arr[i];
        }

        countingSort(arr,max);

        System.out.println("Array : ");
        
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+", ");
        }
    }
}

