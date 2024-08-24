/*Taking user input through Scanner class. */
import java.util.Scanner;

public class Q3_Scanner_Class {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = scanner.nextLine();

        System.out.println("Hello, " + name + "!");
        scanner.close();
    }
}
