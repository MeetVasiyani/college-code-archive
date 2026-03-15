import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of array : ");
        int n = sc.nextInt();

        int [] arr = new int[n];
        for(int i = 0; i < n; i++){
            System.out.println("Enter number for index "+(i+1)+" : ");
            arr[i] = sc.nextInt();
        }

        System.out.println("Enter number to be deleted : ");
        int num = sc.nextInt();

        boolean flag = false;
        for(int i = 0; i < n; i++){
            if(arr[i] == num){
                flag = true;
                while(i < n-1){
                    arr[i] = arr[i+1];
                    i++;
                }
                arr[n-1] = 0;
                break;
            }
        }

        if(!flag){
            System.out.println("Element is not found");
        }else{
            System.out.println("Array : ");
            for(int i = 0; i < n-1; i++){
                System.out.print(arr[i]);
            }
        }

    }
}