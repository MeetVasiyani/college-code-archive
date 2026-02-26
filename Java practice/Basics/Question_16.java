import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number : ");
        int n = sc.nextInt();

        String numStr = Integer.toString(n);

        System.out.print("BCD equivalent: ");

        for(int i = 0; i < numStr.length(); i++){
            int digit = numStr.charAt(i) - '0';

            for(int j = 3; j >=0; j--){
                System.out.print((digit >> j) & 1);
            }

            System.out.print(" ");
        }
    }
}