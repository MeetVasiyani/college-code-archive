/* Declare a class called student having following data members:id_no, no_of_subjects_registered, subject_code, 
subject_credits, grade_obtained and spi. Define constructor and calculate_spi methods.Define main to instantiate an array 
for objects of class student to process data of n students to be given as command line arguments. */
import java.util.Scanner;

class Student {
    int id_no;
    int no_of_subjects_registered;
    int[] subject_code;
    int[] subject_credit;
    String[] grade_obtained;
    double spi;

    public Student() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter ID no:");
        id_no = sc.nextInt();
        System.out.println("Enter no of subjects registered:");
        no_of_subjects_registered = sc.nextInt();
        subject_code = new int[no_of_subjects_registered];
        subject_credit = new int[no_of_subjects_registered];
        grade_obtained = new String[no_of_subjects_registered];

        for (int i = 0; i < no_of_subjects_registered; i++) {
            System.out.println("Enter Subject Code for subject no " + (i + 1) + ":");
            subject_code[i] = sc.nextInt();
            System.out.println("Enter Subject Credit for subject no " + (i + 1) + ":");
            subject_credit[i] = sc.nextInt();
            System.out.println("Enter Grade Obtained for subject no " + (i + 1) + ":");
            grade_obtained[i] = sc.next();
        }

        sc.close();

    }

    public void calculate_spi() {
        double totalCredits = 0;
        double totalPoints = 0;

        for (int i = 0; i < grade_obtained.length; i++) {
            totalCredits += subject_credit[i];
            int gradePoints = convertGradeToPoints(grade_obtained[i]);
            totalPoints += gradePoints * subject_credit[i];
        }
        spi = totalPoints / totalCredits;
    }

    private int convertGradeToPoints(String grade) {
        switch (grade) {
            case "A":
                return 10;
            case "B":
                return 9;
            case "C":
                return 8;
            case "D":
                return 7;
            case "E":
                return 6;
            case "F":
                return 0;
            default:
                return 0;
        }
    }
}

public class Q1_SPI_Calculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of students:");
        int n = sc.nextInt();

        Student[] students = new Student[n];

        for (int i = 0; i < n; i++) {
            students[i] = new Student();
        }

        for (int i = 0; i < n; i++) {
            students[i].calculate_spi();
        }

        for (int i = 0; i < n; i++) {
            System.out.println("SPI of student with ID " + students[i].id_no + " = " + students[i].spi);
        }

        sc.close();

    }
}