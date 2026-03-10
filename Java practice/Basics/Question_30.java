import java.util.*;
class Main{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of array : ");
        int n = sc.nextInt();

        int [] arr = new int[n];
        for(int i = 0; i < n; i++){
            System.out.println("Enter number for index "+(i+1)+" : ");
            arr[i] = sc.nextInt();
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] % 2 == 0){
                res += arr[i];
            }
        }
        System.out.println("Sum of even numbers in array : "+res);
    }
}