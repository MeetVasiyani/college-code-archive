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

        int[] arr = new int[n];

        for(int i = 0; i < n; i++){
            System.out.println("Enter number for index " + (i+1) + " : ");
            arr[i] = sc.nextInt();
        }

        int res = -1;

        /*
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(digitsSum(arr[i]) == digitsSum(arr[j])){
                    res = Math.max(res,(arr[i]+arr[j]));
                }
            }
        }
        */

        HashMap<Integer,Integer> map = new HashMap<>();

        for(int n : arr){
            int sum = digitsSum(n);

            if(map.containsKey(sum)){
                int temp = map.get(sum);
                res = Math.max(res,temp + n);
                map.put(sum,Math.max(temp,n));
            }
            else{
                map.put(sum,n);
            }
        }


        System.out.println("Largest number sum with equal digit sum : "+res);
    }
}

