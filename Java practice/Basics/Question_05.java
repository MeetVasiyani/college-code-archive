import java.util.*;
class Main{
    public static boolean isPrime(int n){
        if(n <= 1){
            return false;
        }

        for(int i = 2; i*i <= n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter range start : ");
        int start = sc.nextInt();

        System.out.println("Enter range end : ");
        int end = sc.nextInt();

        System.out.println("Prime number in range : ");

        for(int i = start; i <= end; i++){
            if(isPrime(i)){
                System.out.println(i);
            }
        }
    }
}