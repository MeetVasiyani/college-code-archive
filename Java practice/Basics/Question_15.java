import java.util.*;

class Main{
    public static int chocolates(int n,int m,int k){
        int total = n / m;
        int wrappers = total;

        while (wrappers >= k) {
            int free = wrappers / k;
            total += free;
            wrappers = free + (wrappers % k);
        }

        return total;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Rupees : ");
        int n = sc.nextInt();
        System.out.println("Enter Chocolate Price : ");
        int m = sc.nextInt();
        System.out.println("Enter Exchange Wrappers : ");
        int k = sc.nextInt();

        int total = chocolates(n,m,k);

        System.out.println("Total Chocolates : "+total);
    }
}