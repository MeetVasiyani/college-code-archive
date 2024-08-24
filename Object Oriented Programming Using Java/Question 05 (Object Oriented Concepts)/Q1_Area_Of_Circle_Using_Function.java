/*Write a program to create circle class with area function to find area of circle. */
import java.util.Scanner;
class Circle {
    double radius;
    Circle(double r) {
        radius=r;
    }
    double area() {
        return Math.PI*radius*radius;
    }
}
public class Q1_Area_Of_Circle_Using_Function{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the radius of the circle:");
        double r = sc.nextDouble();
        Circle c = new Circle(r);
        double a = c.area();
        System.out.println("Area of the circle is:"+a);

        sc.close();
    }
}
