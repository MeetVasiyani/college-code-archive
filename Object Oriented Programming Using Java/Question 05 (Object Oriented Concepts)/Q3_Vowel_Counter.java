/*Create a class which ask the user to enter a sentence, and it should display count of each vowel type in the sentence. The 
program should continue till user enters a word “quit”. Display the total count of each vowel for all sentences. */
import java.util.Scanner;

public class Q3_Vowel_Counter {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int totalA = 0, totalE = 0, totalI = 0, totalO = 0, totalU = 0;

        while (true) {
            System.out.print("Enter a sentence (or 'quit' to exit): ");
            String sentence = scanner.nextLine();

            if (sentence.equalsIgnoreCase("quit")) {
                break;
            }

            int aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;

            for (char c : sentence.toCharArray()) {
                switch (Character.toLowerCase(c)) {
                    case 'a':
                        aCount++;
                        break;
                    case 'e':
                        eCount++;
                        break;
                    case 'i':
                        iCount++;
                        break;
                    case 'o':
                        oCount++;
                        break;
                    case 'u':
                        uCount++;
                        break;
                }
            }

            System.out.println("Vowel counts in this sentence:");
            System.out.println("A: " + aCount);
            System.out.println("E: " + eCount);
            System.out.println("I: " + iCount);
            System.out.println("O: " + oCount);
            System.out.println("U: " + uCount);

            totalA += aCount;
            totalE += eCount;
            totalI += iCount;
            totalO += oCount;
            totalU += uCount;
        }

        System.out.println("\nTotal vowel counts for all sentences:");
        System.out.println("A: " + totalA);
        System.out.println("E: " + totalE);
        System.out.println("I: " + totalI);
        System.out.println("O: " + totalO);
        System.out.println("U: " + totalU);

        scanner.close();
    }
}
