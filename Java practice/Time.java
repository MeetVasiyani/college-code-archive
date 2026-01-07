import java.util.Scanner;

public class Time {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter no. of hours: ");
        int hr = scanner.nextInt();
        System.out.print("Enter no. of mins: ");
        int min = scanner.nextInt();

        double angle = Math.abs(((30 * hr) + (0.5 * min)) - (min * 6));

        System.out.print(angle);

    }
}
