/*Write an application that searches through its command-line argument. If an argument is found that does not begin with 
and upper case letter, display error message and terminate. */

public class Q6_Command_Line_Argument_Checker {

    public static void main(String[] args) {

        if (args.length == 0) {
            System.out.println("Error: No command-line arguments provided.");
            return;
        }

        for (String arg : args) {

            if (!Character.isUpperCase(arg.charAt(0))) {
                System.out.println("Error: Argument '" + arg + "' does not start with an uppercase letter.");
                return;
            }
        }

        System.out.println("All command-line arguments are valid.");
    }
}
