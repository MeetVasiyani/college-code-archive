/*Write an interactive program to print a string entered in a pyramid form. For instance, the string "stream" has to be displayed 
as follows:
 s
 st
 str
 stre
 strea
 stream
  */
import java.util.Scanner;

public class Q7_Pyramid_String {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = scanner.nextLine();

        int len = str.length();

        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print(str.charAt(j));
            }
            System.out.println();
        }

        scanner.close();

    }
}
