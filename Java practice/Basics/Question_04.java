import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number : ");
        int n = sc.nextInt();

        if((n & 1) == 1){
            System.out.println("Odd");
        }else{
            System.out.println("Even");
        }
    }
}