import java.util.Scanner;

public class PronicNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = scanner.nextInt();

        if (isPronic(n)) {
            System.out.println(n + " is a Pronic Number");
        } else {
            System.out.println(n + " is not a Pronic Number");
        }
        scanner.close();
    }

    public static boolean isPronic(int n) {
        if (n < 0) return false;
        for (int i = 0; i <= Math.sqrt(n); i++) {
            if (i * (i + 1) == n) {
                return true;
            }
        }
        return false;
    }
}
