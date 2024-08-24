/* Write an application that reads a file and counts the number of occurrences of digit 5. Supply the file name as a command
line argument. */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Q3_File_Count_Digit_5 {

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java CountDigit5 <filename>");
            return;
        }

        File file = new File(args[0]);
        if (!file.exists()) {
            System.out.println("Error: File not found.");
            return;
        }

        int count = 0;
        try (Scanner scanner = new Scanner(file)) {
            while (scanner.hasNext()) {
                String line = scanner.nextLine();
                for (char c : line.toCharArray()) {
                    if (c == '5') {
                        count++;
                    }
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }

        System.out.println("Number of occurrences of digit 5: " + count);
    }
}