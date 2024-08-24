/* Write a program in Java to demonstrate use of this keyword. Check whether this can access the Static variables of the class 
or not. */
public class Q7_This_Keyword_Demo {

    static int staticVar = 10;

    public static void main(String[] args) {
        @SuppressWarnings("unused")
        Q7_This_Keyword_Demo obj = new Q7_This_Keyword_Demo();

        // Accessing static variable without using this keyword
        System.out.println("Static variable: " + staticVar);

        // Trying to access static variable directly using this keyword (compile-time error)
        //System.out.println("Static variable: " + this.staticVar);
    }
}
