import java.util.*;

class Main {

    public static int toDecimal(int octal) {
        if(octal == 0){
            return 0;
        }
        int decimal = 0, base = 1;
        while(octal > 0){
            int rem = octal % 10;
            if (rem > 7) {
                System.out.println("Invalid Octal Number!");
                return -1;
            }
            decimal += rem * base;
            base *= 8;
            octal /= 10;
        }
        return decimal;
    }

    public static int toOctal(int decimal) {
        if(decimal == 0){
            return 0;
        }
        int octal = 0, base = 1;
        while(decimal > 0){
            int rem = decimal % 8;
            octal += rem * base;
            base *= 10;
            decimal /= 8;
        }
        return octal;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {

            System.out.println("Choose a number:");
            System.out.println("1. Decimal to Octal");
            System.out.println("2. Octal to Decimal");
            System.out.println("3. Exit");

            int choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.println("Enter Decimal Number:");
                    int decimalInput = sc.nextInt();
                    System.out.println("Octal value is: " + toOctal(decimalInput));
                    break;

                case 2:
                    System.out.println("Enter Octal Number:");
                    int octalInput = sc.nextInt();
                    System.out.println("Decimal value is: " + toDecimal(octalInput));
                    break;

                default:
                    System.out.println("Exiting...");
                    return;
            }
        }
    }
}