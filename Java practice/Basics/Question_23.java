import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number : ");
        long n = sc.nextLong();

        long digits = 1;
        long count = 9;
        long start = 1;

        while(n > digits * count){
            n -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }

        start += (n - 1) / digits;

        String num = Long.toString(start);
        char res = num.charAt((int)((n-1) % digits));

        System.out.println("Nth Digit : " + res);
    }
}