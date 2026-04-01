import java.util.*;

class Main {
    public static void radixSort(int[] arr,int exp){
        int n = arr.length;
        int [] output = new int[n];
        int [] count = new int[10];

        for(int i = 0; i < n; i++){
            int digit = (arr[i]/exp) % 10;
            count[digit]++;
        }

        for(int i = 1; i < 10; i++){
            count[i] += count[i-1];
        }

        for(int i = n-1; i >= 0; i--){
            int digit = (arr[i]/exp) % 10;
            output[count[digit]-1] = arr[i];
            count[digit]--;
        }
        for(int i = 0; i < n; i++){
            arr[i] = output[i];
        }
    }
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of array : ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        int max = -1;

        for(int i = 0; i < n; i++){
            System.out.println("Enter number for index " + (i+1) + " : ");
            arr[i] = sc.nextInt();
            if(arr[i] > max){
                max = arr[i];
            }
        }

        for(int exp = 1; max/exp > 0; exp *=10){
            radixSort(arr,exp);
        }

        System.out.println("Array : ");
        
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+", ");
        }
    }
}

