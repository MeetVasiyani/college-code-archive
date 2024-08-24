/*Write a program that creates and initializes a four integer element array. Calculate and display the average of its values. */

public class Q3_Average_Of_Array {

    public static void main(String[] args) {

        int[] numbers = {10, 20, 30, 40};

        int sum = 0;
        for (int number : numbers) {
            sum += number;
        }

        double average = (double) sum / numbers.length;

        System.out.println("The average of the array elements is: " + average);
    }
}
