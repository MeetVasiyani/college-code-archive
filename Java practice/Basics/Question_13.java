import java.util.*;

class Main{
    public static boolean isAutomorphic(int n){
        
        if(n < 0) return false;

        int temp = n;
        int squared = n*n;
        while(temp > 0){
            if(temp % 10 != squared % 10){
                return false;
            }
            temp /= 10;
            squared /= 10;
        }
        return true;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number : ");
        int n = sc.nextInt();

        if(isAutomorphic(n)){
            System.out.println("Number is automorphic.");
        }
        else{
            System.out.println("Number is not automorphic.");
        }
    }
}