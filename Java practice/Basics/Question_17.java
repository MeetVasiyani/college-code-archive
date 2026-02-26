import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter binary number : ");
        int binary = sc.nextInt();

        int decimal = 0;
        int base = 1;

        while(binary > 0){
            int digit = binary % 2;
            decimal += digit * base;
            base *= 2;
            binary /= 10;
        }

        System.out.println("Decimal equivalent: " + decimal);

    }
}