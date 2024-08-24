/* Write a program to calculate the area of circle. */

import java.util.Scanner;

public class Q4_Area_Of_Circle {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the radius of the circle: ");
        double radius = scanner.nextDouble();

        double area = Math.PI * radius * radius;

        System.out.println("The area of the circle is: " + area);

        scanner.close();
    }
}
