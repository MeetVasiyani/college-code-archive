/* Write a program to get 2 numbers from the user and print the sum of two numbers using command line and Scanner class. */

import java.util.Scanner;

public class Q1_Sum_Of_Two_Numbers_Using_Scanner_Class {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        int num1 = scanner.nextInt();

        System.out.print("Enter the second number: ");
        int num2 = scanner.nextInt();

        int sum = num1 + num2;

        System.out.println("The sum of the two numbers is: " + sum);
        scanner.close();
    }
}
