import java.util.*;

class Main{
    public static boolean isPronic(int n){
        for (int i = 0; i * (i + 1) <= n; i++) {
            if (i * (i + 1) == n) {
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number : ");
        int n = sc.nextInt();

        if(isPronic(n)){
            System.out.println("The number is Pronic.");
        }
        else{
            System.out.println("Number is not Pronic.");
        }
    }
}