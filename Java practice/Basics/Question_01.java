import java.util.*;

class Main{
    public static long factorial(int n){
        long fact = 1;
        for(int i = 1; i <= n; i++){
            fact = fact * i;
        }
        return fact;
    }
    public static long recursivefactorial(int n){
        if(n == 0){
            return 1;
        }
        return n * recursivefactorial(n-1);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter an integer : ");
        int n = sc.nextInt();

        if(n < 0){
            System.out.println("Negative numbers not allowed.");
        }
        else{
            long fact1 = factorial(n);
            System.out.println("Factorial : "+fact1);

            long fact2 = recursivefactorial(n);
            System.out.println("Factorial : "+fact2);
        }
        sc.close();
    }
}
