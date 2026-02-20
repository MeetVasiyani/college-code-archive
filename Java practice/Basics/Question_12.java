import java.util.*;
class Main{
    public static boolean isKarpekar(int n){
        int squared = n*n;
        int temp = 10;
        while(temp <= squared){
            int left = squared/temp;
            int right = squared % temp;
            if(right != 0 && n == (left+right)){
                return true;
            }
            temp *= 10;
        }
        return false;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter a number : ");
        int n = sc.nextInt();

        if(isKarpekar(n)){
            System.out.println("Given number is Karpekar number.");
        }else{
            System.out.println("Given number is not a Karpekar number.");
        }
    }
}