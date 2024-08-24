/* 
The marks obtained by a student in 5 different subjects are input through the keyboard. 
The student gets a division as per the following rules:
        I. Percentage above or equals to 60- first division
        II. Percentage between 50 to 59-second division
        III. Percentage between 40 and 49-Third division
        IV. Percentage less than 40-fail
 Write a program to calculate the division obtained by the student. 
*/

import java.util.Scanner;

public class Q1_Student_Result {

    public static void main(String[] args) {

        int subject1, subject2, subject3, subject4, subject5;
        double totalMarks, percentage;
        String division;

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter marks for subject 1: ");
        subject1 = scanner.nextInt();
        System.out.print("Enter marks for subject 2: ");
        subject2 = scanner.nextInt();
        System.out.print("Enter marks for subject 3: ");
        subject3 = scanner.nextInt();
        System.out.print("Enter marks for subject 4: ");
        subject4 = scanner.nextInt();
        System.out.print("Enter marks for subject 5: ");
        subject5 = scanner.nextInt();

        scanner.close();

        totalMarks = subject1 + subject2 + subject3 + subject4 + subject5;

        percentage = (totalMarks / 500) * 100;

        if (percentage >= 60) {
            division = "First";
        } 
        else if (percentage >= 50) {
            division = "Second";
        } 
        else if (percentage >= 40) {
            division = "Third";
        } 
        else {
            division = "Fail";
        }

        System.out.println("Total marks: " + totalMarks+"/500");
        System.out.println("Percentage: " + percentage);
        System.out.println("Division: " + division);
    }
}
