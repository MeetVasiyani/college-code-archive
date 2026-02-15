import java.util.*;

class Main{
    public static boolean isArmstrong(int n){
        if (n < 0) {
            return false;
        }
        int len = 0,temp = n;
        
        do{
            len++;
            temp /= 10;
        }while(temp != 0);

        int res = 0;
        temp = n;

        do{
            int digit = temp % 10;
            res += (int)Math.pow(digit,len);
            temp = temp/10;
        }while(temp != 0);

        return res == n;

    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number : ");
        int n = sc.nextInt();

        if(isArmstrong(n)){
            System.out.println("Number is Armstrong");
        }else{
            System.out.println("Number is not Armstrong");
        }
    }
}