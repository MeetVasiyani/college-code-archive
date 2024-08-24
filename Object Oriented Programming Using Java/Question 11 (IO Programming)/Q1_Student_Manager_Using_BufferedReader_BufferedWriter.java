/*Define the student manager program to manipulate the student information from files by using the BufferedReader and BufferedWriter. */

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Student {
    int id;
    String name;
    double gpa;

    public Student(int id, String name, double gpa) {
        this.id = id;
        this.name = name;
        this.gpa = gpa;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getGpa() {
        return gpa;
    }

    @Override
    public String toString() {
        return "ID: " + id + ", Name: " + name + ", GPA: " + gpa;
    }

    public String toFileString() {
        return id + "," + name + "," + gpa;
    }

    public static Student fromFileString(String fileString) {
        String[] parts = fileString.split(",");
        int id = Integer.parseInt(parts[0]);
        String name = parts[1];
        double gpa = Double.parseDouble(parts[2]);
        return new Student(id, name, gpa);
    }
}

public class Q1_Student_Manager_Using_BufferedReader_BufferedWriter {
    public static final String FILE_NAME = "students.txt";
    public static List<Student> students = new ArrayList<>();

    public static void main(String[] args) {
        loadStudentsFromFile();
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\nStudent Manager");
            System.out.println("1. Add Student");
            System.out.println("2. Display All Students");
            System.out.println("3. Search Student by ID");
            System.out.println("4. Delete Student by ID");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    addStudent(sc);
                    break;
                case 2:
                    displayAllStudents();
                    break;
                case 3:
                    searchStudentById(sc);
                    break;
                case 4:
                    deleteStudentById(sc);
                    break;
                case 5:
                    saveStudentsToFile();
                    System.out.println("Exiting program...");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    public static void loadStudentsFromFile() {
        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                students.add(Student.fromFileString(line));
            }
        } catch (IOException e) {
            System.out.println("Error reading from file: " + e.getMessage());
        }
    }

    public static void saveStudentsToFile() {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(FILE_NAME))) {
            for (Student stu : students) {
                bufferedWriter.write(stu.toFileString());
                bufferedWriter.newLine();
            }
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }
    }

    public static void addStudent(Scanner sc) {
        System.out.print("Enter student ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter student name: ");
        String name = sc.nextLine();

        System.out.print("Enter student GPA: ");
        double gpa = sc.nextDouble();
        sc.nextLine();

        students.add(new Student(id, name, gpa));
        System.out.println("Student added successfully.");
    }

    public static void displayAllStudents() {
        if (students.isEmpty()) {
            System.out.println("No students found.");
        } else {
            System.out.println("All Students:");
            for (Student stu : students) {
                System.out.println(stu);
            }
        }
    }

    public static void searchStudentById(Scanner sc) {
        System.out.print("Enter student ID to search: ");
        int id = sc.nextInt();
        sc.nextLine();

        boolean found = false;
        for (Student stu : students) {
            if (stu.getId() == id) {
                System.out.println("Student found: " + stu);
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Student with ID " + id + " not found.");
        }
    }

    public static void deleteStudentById(Scanner sc) {
        System.out.print("Enter student ID to delete: ");
        int id = sc.nextInt();
        sc.nextLine();

        boolean found = false;
        for (Student stu : students) {
            if (stu.getId() == id) {
                students.remove(stu);
                System.out.println("Student with ID " + id + " deleted successfully.");
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Student with ID " + id + " not found.");
        }
    }
}