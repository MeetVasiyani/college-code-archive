/*Write a program to convert temperature from Fahrenheit to Celsius. (Formula : c = f-32*5/9 ) */
import java.util.Scanner;

public class Q5_Fahrenheit_To_Celsius {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter temperature in Fahrenheit: ");
        double fahrenheit = scanner.nextDouble();

        double celsius = (fahrenheit - 32) * 5/9;

        System.out.println("Temperature in Celsius: " + celsius);

        scanner.close();
    }
}
