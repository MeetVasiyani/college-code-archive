import java.util.*;

class Main{
    public static int isUgly(int n){

        if(n <= 0) return false;

        int [] list = {2,3,5};
        for(int i : list){
            while(n % i == 0){
                n /= i;
            }
        }

        return n == 0;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number : ");
        int n = sc.nextInt();

        if(isUgly(n)){
            System.out.println("It is an ugly number.");
        }else{
            System.out.println("It is not an ugly number.");
        }
    }
}