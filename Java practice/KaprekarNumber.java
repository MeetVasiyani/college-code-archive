import java.util.Scanner;

public class KaprekarNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = scanner.nextInt();

        if (isKaprekar(n)) {
            System.out.println(n + " is a Kaprekar number");
        } else {
            System.out.println(n + " is not a Kaprekar number");
        }
        scanner.close();
    }

    public static boolean isKaprekar(int n) {
        if (n < 1) return false;
        if (n == 1) return true;

        long square = (long) n * n;
        long count = 10;

        while (count <= square) {
            long left = square / count;
            long right = square % count;

            if (right > 0 && left + right == n) {
                return true;
            }
            count *= 10;
        }
        return false;
    }

}
