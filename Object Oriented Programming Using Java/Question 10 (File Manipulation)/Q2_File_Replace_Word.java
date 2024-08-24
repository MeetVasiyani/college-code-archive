/*Write a program to replace all “word1” by “word2” from a file1, and output is written to file2 file and display the no. of 
replacement. */
import java.io.*;

public class Q2_File_Replace_Word {
    public static void main(String[] args) {
        if (args.length < 4) {
            System.out.println("Usage: java Replace <inputFile> <outputFile> <word1> <word2>");
            return;
        }

        String inputFile = args[0];
        String outputFile = args[1];
        String word1 = args[2];
        String word2 = args[3];

        try {
            File file1 = new File(inputFile);
            File file2 = new File(outputFile);

            if (!file1.exists()) {
                throw new FileNotFoundException("Input file does not exist: " + inputFile);
            }

            BufferedReader r1 = new BufferedReader(new FileReader(file1));
            BufferedWriter w1 = new BufferedWriter(new FileWriter(file2));

            String line = r1.readLine();
            while (line != null) {
                String[] words = line.split(" ");
                StringBuilder changedLine = new StringBuilder();
                for (String word : words) {
                    if (word.equals(word1)) {
                        changedLine.append(word2).append(" ");
                    } else {
                        changedLine.append(word).append(" ");
                    }
                }
                w1.write(changedLine.toString().trim());
                w1.newLine();
                line = r1.readLine();
            }

            w1.close();
            r1.close();
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
