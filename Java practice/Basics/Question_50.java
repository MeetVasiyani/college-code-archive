import java.util.*;

class Main {
    public static void shellSort(int[] arr){
        int n = arr.length;

        for(int gap = n/2; gap > 0; gap /= 2){

            for(int i = gap; i < n; i++){
                int temp = arr[i];
                int j = i;
                while(j >= gap && arr[j-gap] > temp){
                    arr[j] = arr[j-gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
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

        shellSort(arr);

        System.out.println("Array : ");
        
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+", ");
        }
    }
}

