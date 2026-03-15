import java.util.*;
class Main{
    static int n;
    static int isInArray(int a[], int m) {
        if (n == 0){
            return 0;
        }
        if (a[n - 1] == m){
            return 1;
        }
        n--;
        return isInArray(a, m);
    }
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of array : ");
        n = sc.nextInt();

        int [] arr = new int[n];
        for(int i = 0; i < n; i++){
            System.out.println("Enter number for index "+(i+1)+" : ");
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter element to search: ");
        int m = sc.nextInt();

        if (isInArray(arr, m) == 1){
            System.out.println("Element is present in array.");
            }
        else{
            System.out.println("Element is NOT present in array.");
            }
    }
}