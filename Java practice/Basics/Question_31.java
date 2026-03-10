import java.util.*;
class Main{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of array : ");
        int n = sc.nextInt();

        int [] arr = new int[n+1];
        for(int i = 0; i < n; i++){
            System.out.println("Enter number for index "+(i+1)+" : ");
            arr[i] = sc.nextInt();
        }

        System.out.println("Enter index for number : ");
        int index = sc.nextInt();

        System.out.println("Enter number to be inserted : ");
        int num = sc.nextInt();

        for(int i = n; i>= index; i--){
            arr[i] = arr[i-1];
        }

        arr[index-1] = num;

        System.out.println("Array : ");
        for(int i = 0; i < n+1; i++){
            System.out.print(arr[i]);
        }

    }
}