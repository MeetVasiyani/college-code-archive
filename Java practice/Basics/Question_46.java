import java.util.*;

class Main {
    public static void insertionSort(int[] bucket,int size){

        for(int i = 1; i < size; i++){

            int j = i-1, temp = bucket[i];

            while(j >= 0 && bucket[j] > temp){
                bucket[j+1] = bucket[j];
                j--;
            }

            bucket[j+1] = temp;
        }
    } 
    public static void bucketSort(int[] arr){
        int n = arr.length;

        int [][] buckets = new int [10][n];
        int [] bucketCount = new int[10];

        for(int i = 0; i < n; i++){
            int bucketIndex = arr[i] / 10;
            buckets[bucketIndex][bucketCount[bucketIndex]] = arr[i];
            bucketCount[bucketIndex]++;
        }

        for(int i = 0; i < 10; i++){
            insertionSort(buckets[i],bucketCount[i]);
        }

        int index = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < bucketCount[i]; j++){
                arr[index++] = buckets[i][j];
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

        bucketSort(arr);

        System.out.println("Array : ");
        
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+", ");
        }
    }
}

