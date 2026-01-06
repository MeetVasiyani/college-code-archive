import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int [] arr = new int[10];
        for(int i = 1; i < 6; i++){
            arr[i-1] = i;
        }
        
        System.out.print("Enter the integer : ");
        int val = sc.nextInt();
        
        for(int i = 8; i >= pos; i--){
            arr[i+1] = arr[i];
        }
        arr[pos] = val;
        for(int i = 0; i < 10; i++){
            System.out.print(arr[i]);
        }
    }
}