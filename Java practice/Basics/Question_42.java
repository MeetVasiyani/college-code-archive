import java.util.*;

class Main {
    public static int digitsSum(int k){
        int sum = 0;
        while(k > 0){
            int digit = k % 10;
            sum += digit;
            k /= 10;
        }
        return sum;
    }
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of array : ");
        int n = sc.nextInt();

        int[] arr1 = new int[n];

        for(int i = 0; i < n; i++){
            System.out.println("Enter number for index " + (i+1) + " : ");
            arr1[i] = sc.nextInt();
        }

        int[] arr2 = new int[n];

        for(int i = 0; i < n; i++){
            System.out.println("Enter number for index " + (i+1) + " : ");
            arr2[i] = sc.nextInt();
        }

        Arrays.sort(arr1);
        Arrays.sort(arr2);

        int [] temp = new int [2*n];

        int left = 0,right = 0,count = 0;

        while(left < n && right < n){
            if(arr1[left] < arr2[right]){
                temp[count] = arr1[left];
                count++;
                left++;
            }
            else{
                temp[count] = arr2[right];
                count++;
                right++;
            }
        }
        while(left < n){
            temp[count] = arr1[left];
            count++;
            left++;
        }
        while(right < n){
            temp[count] = arr2[right];
            count++;
            right++;
        }

        int mid1 = temp[n-1];
        int mid2 = temp[n];

        double median = (mid1+mid2) / 2.0;

        System.out.println("Median number : "+median);
    }
}

