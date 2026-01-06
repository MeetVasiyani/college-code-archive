import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter n : ");
        int n = sc.nextInt();
        for(int i = 1; i <= n; i++){
            int count = i;
            int next = n - 1;
            for(int j = i; j > 0; j--){
                System.out.print(count);
                count += next;
                next--;
            }
            System.out.println();
        }
    }
}