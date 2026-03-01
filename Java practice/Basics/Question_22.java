import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number : ");
        int n1 = sc.nextInt();

        System.out.println("Enter a number : ");
        int n2 = sc.nextInt();

        int xor = n1 ^ n2;
        int count = 0;

        while(xor > 0){
            count += xor & 1;
            xor >>= 1;
        }

        System.out.println("Distance : " + count);
    }
}