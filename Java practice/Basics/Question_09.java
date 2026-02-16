import java.util.*;

class Main{
    public static int multiply(int x,int y){
        int sum = 0;
        for(int i = 0; i < y; i++){
            sum += x;
        }
        return sum;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter base (a): ");
        int a = sc.nextInt();

        System.out.print("Enter exponent (b): ");
        int b = sc.nextInt();

        if(b < 0){
            System.out.println("Negative exponent not supported.");
            sc.close();
            return;
        }

        int res = 1;

        for(int i = 0; i < b; i++){
            res = multiply(res,a);
        }

        System.out.println("Result: " + res);

        sc.close();
    }
}