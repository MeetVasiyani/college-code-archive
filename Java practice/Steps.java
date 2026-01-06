import java.util.Scanner;

class Main {

    static int countWays(int n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of steps: ");
        int n = sc.nextInt();

        System.out.println("Number of ways: " + countWays(n));
    }
}
