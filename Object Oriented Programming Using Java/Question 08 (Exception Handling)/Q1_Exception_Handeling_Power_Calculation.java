/* Write a method for computing xy doing repetitive multiplication. X and y are of type integer and are to be given as command 
line arguments. Raise and handle exception(s) for invalid values of x and y. */

public class Q1_Exception_Handeling_Power_Calculation {

    public static void main(String[] args) {
        try {

            int x = Integer.parseInt(args[0]);
            int y = Integer.parseInt(args[1]);

            if (x < 0 || y < 0) {
                throw new IllegalArgumentException("Input values must be non-negative.");
            }

            int result = 1;
            for (int i = 0; i < y; i++) {
                result *= x;
            }

            System.out.println(x + " raised to the power " + y + " is " + result);
        }catch (NumberFormatException e) {
            System.err.println("Invalid input format. Please provide two integer values as command line arguments.");
        }catch (IllegalArgumentException e) {
            System.err.println(e.getMessage());
        }
    }
}
