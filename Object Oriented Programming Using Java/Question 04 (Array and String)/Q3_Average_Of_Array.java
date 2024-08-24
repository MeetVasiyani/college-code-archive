/*Write a program that creates and initializes a four integer element array. Calculate and display the average of its values. */

import java.util.Scanner;

public class Q3_Average_Of_Array {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] numbers = new int[4];

        System.out.println("Please enter the integers one by one:");

        for (int i = 0; i < 4; i++) {
            System.out.print("Enter integer " + (i + 1) + ": ");
            numbers[i] = sc.nextInt();
        }

        sc.close();

        int sum = 0;
        for (int number : numbers) {
            sum += number;
        }

        double average = (double) sum / 4;

        System.out.println("The average of the array elements is: " + average);
    }
}
