/* Write a program to check that whether the name given from command line is file or not? If it is a le then print the size of le 
and if it is directory then it should display the name of all les in it. */

import java.io.File;

public class Q2_File_Or_Directory_Checker {

    public static void main(String[] args) {

        if (args.length != 1) {
            System.out.println("Usage: java FileChecker <file_name>");
            return;
        }

        String fileName = args[0];

        File file = new File(fileName);

        if (!file.exists()) {
            System.out.println("Error: File does not exist.");
            return;
        }

        if (file.isDirectory()) {

            System.out.println("Directory: " + fileName);
            String[] files = file.list();
            if (files != null) {
                for (String f : files) {
                    System.out.println(f);
                }
            }
        } else {
            System.out.println("File: " + fileName);
            System.out.println("Size: " + file.length() + " bytes");
        }
    }
}