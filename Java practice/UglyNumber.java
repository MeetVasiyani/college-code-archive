import java.util.Scanner;

public class UglyNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = scanner.nextInt();

        if (isUgly(n)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
        scanner.close();
    }

    public static boolean isUgly(int n) {
        if (n <= 0) return false;
        
        int[] divisors = {2, 3, 5};
        for (int d : divisors) {
            while (n % d == 0) {
                n /= d;
            }
        }
        return n == 1;
    }
}
