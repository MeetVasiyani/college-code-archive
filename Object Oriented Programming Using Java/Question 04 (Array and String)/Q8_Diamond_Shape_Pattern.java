/* Write an interactive program to print a diamond shape. For example, if user enters the number 3, the diamond will be as 
follows:
 *
 * *
 * * *
 * *
 * 
  
 */
import java.util.Scanner;

public class Q8_Diamond_Shape_Pattern {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of rows: ");
        int rows = scanner.nextInt();

        scanner.close();

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }

        for (int i = rows - 1; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}

