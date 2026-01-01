import java.util.Scanner;

public class AutomorphicNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = scanner.nextInt();

        if (isAutomorphic(n)) {
            System.out.println(n + " is an Automorphic number");
        } else {
            System.out.println(n + " is not an Automorphic number");
        }
        scanner.close();
    }

    public static boolean isAutomorphic(int n) {
        if (n < 0) return false; 
        long square = (long) n * n;
        
        int temp = n;
        while (temp > 0) {
            if (temp % 10 != square % 10) {
                return false;
            }
            temp /= 10;
            square /= 10;
        }
        return true;
    }
}
