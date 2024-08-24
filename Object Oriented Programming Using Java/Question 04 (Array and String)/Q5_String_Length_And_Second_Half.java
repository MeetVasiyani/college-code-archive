/*Write a program to find length of string and print second half of the string. */
import java.util.Scanner;

public class Q5_String_Length_And_Second_Half {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String str = scanner.nextLine();

        int length = str.length();
        System.out.println("Length of the string: " + length);

        int halfLength = length / 2;
        String secondHalf = str.substring(halfLength);

        System.out.println("Second half of the string: " + secondHalf);

        scanner.close();
    }
}