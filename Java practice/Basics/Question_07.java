import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter n : ");
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("Please enter a positive count.");
            return;
        }

        int num = 0,max = Integer.MIN_VALUE, min = Integer.MAX_VALUE, res = 0;
        for(int i = 0; i < n; i++){
            System.out.println("Enter a number : ");
            num = sc.nextInt();

            if(num > max){
                max = num;
            }
            if(num < min){
                min = num;
            }
            res += num;
        }

        System.out.println("Maximum : "+max);
        System.out.println("Minimum : "+min);
        System.out.println("Average : "+((double) res / n));
    }
}