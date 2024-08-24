/* 
Write a complete program to accept N integer numbers from the command line. Raise and handle exceptions for following 
cases : 
 i.- when a number is –ve
 ii.- when a number is evenly divisible by 10
 iii.- when a number is greater than 1000 and less than 2000
 iv.- when a number is greater than 7000
 Skip the number if an exception is raised for it, otherwise add it to nd total sum. 
 */
import java.util.Scanner;

public class Q2_Exception_Handling_Sum {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sum = 0;

        System.out.println("Enter the number of integers: ");
        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.println("Enter integer " + (i + 1) + ": ");
            int num = scanner.nextInt();

            try {
                if (num < 0) {
                    throw new IllegalArgumentException("Number cannot be negative.");
                } 
                else if (num % 10 == 0) {
                    throw new ArithmeticException("Number is evenly divisible by 10.");
                } 
                else if (num > 1000 && num < 2000) {
                    throw new IndexOutOfBoundsException("Number is between 1000 and 2000.");
                } 
                else if (num > 7000) {
                    throw new IllegalStateException("Number is greater than 7000.");
                } 
                else {
                    sum += num;
                }
            } catch (IllegalArgumentException | ArithmeticException | IndexOutOfBoundsException | IllegalStateException e) {
                System.err.println("Skipping number due to exception: " + e.getMessage());
            }
        }

        System.out.println("The sum of valid numbers is: " + sum);

        scanner.close();
    }
}
