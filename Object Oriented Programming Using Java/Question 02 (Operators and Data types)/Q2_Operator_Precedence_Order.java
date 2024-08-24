/* 
Demonstrate the Operator precedence. 
 i. 10 + 20 * 30
 ii. 100 / 10 * 100
 iii. 5 * 4 / 4 % 3
 iv. 100 + 200 / 10 – 3 * 10 */


public class Q2_Operator_Precedence_Order {

    public static void main(String[] args) {
        // i. 10 + 20 * 30
        int result1 = 10 + 20 * 30;
        System.out.println("10 + 20 * 30 = " + result1); // Output: 610

        // ii. 100 / 10 * 100
        int result2 = 100 / 10 * 100;
        System.out.println("100 / 10 * 100 = " + result2); // Output: 1000

        // iii. 5 * 4 / 4 % 3
        int result3 = 5 * 4 / 4 % 3;
        System.out.println("5 * 4 / 4 % 3 = " + result3); // Output: 1

        // iv. 100 + 200 / 10 – 3 * 10
        int result4 = 100 + 200 / 10 - 3 * 10;
        System.out.println("100 + 200 / 10 - 3 * 10 = " + result4); // Output: 170
    }
}
