/*Demonstrate the use of Final Keyword. */

class Q6_Final_Keyword_Demo {

    // Final variable
    final int MAX_VALUE = 100;

    // Final method
    final void printMessage() {
        System.out.println("This is a final method.");
    }

    public static void main(String[] args) {
        Q6_Final_Keyword_Demo demo = new Q6_Final_Keyword_Demo();

        // Trying to modify the final variable
        // demo.MAX_VALUE = 200; // Compile-time error: cannot assign a value to final variable MAX_VALUE

        // Calling the final method
        demo.printMessage();
    }
}
