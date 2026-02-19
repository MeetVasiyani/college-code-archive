import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number : ");
        int num1 = sc.nextInt();

        System.out.println("Enter a number : ");
        int num2 = sc.nextInt();

        int big = num1 > num2 ? num1 : num2;
        int small = num1 < num2 ? num1 : num2;

        if(small == 0){
            System.out.println("Division by zero not allowed");
            return;
        }

        int count = 0;
        while(big >= small){
            count++;
            big -= small;
        }

        System.out.println("Quotient : "+count);
        System.out.println("Remainder : "+big);

    }
}