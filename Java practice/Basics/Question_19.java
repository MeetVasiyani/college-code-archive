import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter an hexadecimal string : ");
        String n = sc.nextLine().toUpperCase();

        int decimal = 0;
        int base = 1;

        for (int i = n.length() - 1; i >= 0; i--) {
            char ch = n.charAt(i);
            int value;

            if (Character.isDigit(ch)) {
                value = ch - '0';
            } else {
                value = ch - 'A' + 10;
            }

            decimal += value * base;
            base *= 16;
        }

        if(decimal == 0){
            System.out.println("Octal equivalent: " + 0);
            return;
        }

        String octal = "";
        while(decimal != 0){
            int digit = decimal % 8;
            octal = digit + octal;
            decimal /= 8;
        }

        System.out.println("Octal equivalent: " + octal);
        
    }
}