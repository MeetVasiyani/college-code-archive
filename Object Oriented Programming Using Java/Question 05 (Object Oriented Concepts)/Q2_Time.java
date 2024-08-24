/* Define Time class with constructor to initialize hour and minute. Also define addition method to add two time objects */
import java.util.Scanner;

public class Q2_Time {
    int hour;
    int minute;

    public Q2_Time(int hour, int minute) {
        this.hour = hour;
        this.minute = minute;
    }

    public void add(Q2_Time other) {
        int totalMinutes = this.hour * 60 + this.minute + other.hour * 60 + other.minute;
        this.hour = totalMinutes / 60;
        this.minute = totalMinutes % 60;
    }

    public String toString() {
        return String.format("%02d:%02d", hour, minute);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first time (HH:MM): ");
        int hour1 = scanner.nextInt();
        int minute1 = scanner.nextInt();

        System.out.print("Enter the second time (HH:MM): ");
        int hour2 = scanner.nextInt();
        int minute2 = scanner.nextInt();

        Q2_Time time1 = new Q2_Time(hour1, minute1);
        Q2_Time time2 = new Q2_Time(hour2, minute2);

        time1.add(time2);

        System.out.println("The sum of the two times is: " + time1);

        scanner.close();
    }
}
