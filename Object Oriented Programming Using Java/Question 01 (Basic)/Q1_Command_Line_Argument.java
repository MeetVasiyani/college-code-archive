/* Taking user input through Command Line Argument. */
public class Q1_Command_Line_Argument {

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide a name as an argument.");
        } 
        else {
            String name = args[0];
            System.out.println("Hello, " + name + "!");
        }
    }
}
