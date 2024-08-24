import java.io.*;

public class Q1_File_Counter {
    public static void main(String[] args) {
        try {
            File file = new File("abc.txt");
            if (!file.exists()) {
                throw new FileNotFoundException("File does not exist");
            }

            int charCount = 0;
            int wordCount = 0;
            int lineCount = 0;

            FileReader fileReader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            String line = bufferedReader.readLine();

            while (line != null) {
                lineCount++;
                charCount += line.length();
                String[] words = line.trim().split("\\s+");
                wordCount += words.length;
                line = bufferedReader.readLine();
            }

            System.out.println("Number of lines: " + lineCount);
            System.out.println("Number of words: " + wordCount);
            System.out.println("Number of characters: " + charCount);

            bufferedReader.close();
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
