/*Write a program to find maximum no from given 3 no.*/
import java.util.Scanner;
public class Q3_Maximum_Number {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the first number:");
        int a = scanner.nextInt();
        System.out.println("Enter the second number:");
        int b = scanner.nextInt();
        System.out.println("Enter the third number:");
        int c = scanner.nextInt();

        scanner.close();

        int max = a;
        if (b > max) {
            max = b;
        }
        if (c > max) {
            max = c;
        }
        System.out.println("The maximum number is: " + max);
    }
}
