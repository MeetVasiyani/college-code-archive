import java.util.*;

class Main {
    public static int sortedOccurrence(int[] arr,int k){
        int n = arr.length,count = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] == k){
                count++;
            }
            if(i > 0 && arr[i] < arr[i-1]){
                return 0;
            }
        }
        return count >= 3 ? 1 : 0;
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

        System.out.println("Enter target number : ");
        int k = sc.nextInt();

        int res = sortedOccurrence(arr,k);

        System.out.println("The function returns : " + res);
    }
}

