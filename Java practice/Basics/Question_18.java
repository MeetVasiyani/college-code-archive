import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int octal = sc.nextInt();

        int decimal = 0,base = 1;
        while(octal != 0){
            int digit = octal % 10;
            decimal += digit * base;
            base *= 8;
            octal /= 10;
        }

        if(decimal == 0){
            System.out.println("Hexadecimal equivalent: " + 0);
            return;
        }

        String hex = "";
        char [] hexChars = {
            '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
        };

        while(decimal != 0){
            int rem = decimal % 16;
            hex = hexChars[rem] + hex;
            decimal /= 16;
        }

        System.out.println("Hexadecimal equivalent: " + hex);
    }
}