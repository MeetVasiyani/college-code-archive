/*  Write a java program to do sum of command line argument passed as two Double numbers.*/

public class Q1_Sum_Of_Doubles_Using_Command_Line {

    public static void main(String[] args) {

        if (args.length != 2) {
            System.out.println("Please provide two double numbers as command line arguments.");
            return;
        }

        double num1 = Double.parseDouble(args[0]);
        double num2 = Double.parseDouble(args[1]);

        double sum = num1 + num2;

        System.out.println("Sum of " + num1 + " and " + num2 + " is: " + sum);
    }
}
