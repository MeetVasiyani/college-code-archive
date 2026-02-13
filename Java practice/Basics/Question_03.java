import java.util.*;
class Main{
    public static void main(String[] srgs){
        Scanner sc = new Scanner(System.in);
        System.out .print("Enter a number : ");
        int n = sc.nextInt();
        int even = 0, odd = 0;
        while(n > 0){
            int digit = n % 10;
            if(digit % 2 == 0){
                even++;
            }else{
                odd++;
            }
            n = n/10;
        }
        System.out.println("Even : "+even);
        System.out.println("Odd : "+odd);
    }
}