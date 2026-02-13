import java.util.*;
class Main{
    public static int sumofdigits(int n){
        n = Math.abs(n);

        if(n == 0){
            return 0;
        }
        return (n%10) + sumofdigits(n/10);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number : ");
        int n = sc.nextInt();

        int sum1  = sumofdigits(n);

        int sum2 = 0, temp = Math.abs(n);
        while(temp > 0){
            int digit = temp%10;
            sum2 += digit;
            temp = temp/10;
        }

        System.out.println("Sum of digits : "+sum1);
        System.out.println("Sum of digits : "+sum2);
    }
}