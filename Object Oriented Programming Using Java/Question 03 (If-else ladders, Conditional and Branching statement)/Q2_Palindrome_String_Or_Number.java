/* Write a program to find that given number or string is palindrome or not. */
import java.util.Scanner;

public class Q2_Palindrome_String_Or_Number {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number or string: ");
        String input = scanner.nextLine();

        scanner.close();

        int length = input.length();
        boolean Palindrome = true;

        for (int i = 0; i < length / 2; i++) {
            if (input.charAt(i) != input.charAt(length - 1 - i)) {
                Palindrome = false;
                break;
            }
        }

        if (Palindrome) {
            System.out.println(input + " is a palindrome.");
        } else {
            System.out.println(input + " is not a palindrome.");
        }
    }
}
