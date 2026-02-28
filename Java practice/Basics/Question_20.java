import java.util.*;

class Main{
    public static int toDecimal(String n){
        n = n.toUpperCase();
        int len = n.length();
        int dec = 0, base = 1, i = len-1;
        while(i >= 0){
            char ch = n.charAt(i);
            if(Character.isDigit(ch)){
                dec += (ch-'0')*base;
            }
            else{
                dec += ((ch-'A')+10)*base;
            }
            base *= 16;
            i--;
        }
        return dec;
    }
    public static String toHexadecimal(int n){
        if(n == 0){
            return "0";
        }
        char[] hexChar = {
            '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
        };
        String hex = "";
        while(n > 0){
            int rem = n % 16;
            hex = hexChar[rem] + hex;
            n /= 16;
        }
        return hex;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        while(true){
            System.out.println("Choose a number : ");
            System.out.println("1. Decimal to Hexadecimal : ");
            System.out.println("2. HexaDecimal to decimal : ");
            int temp = sc.nextInt();
            switch(temp){
                case 1:
                    System.out.println("Enter Decimal Number : ");
                    int n = sc.nextInt();
                    System.out.println("HexaDecimal value is : "+ toHexadecimal(n));
                    break;
                case 2:
                    System.out.println("Enter Hexadecimal String : ");
                    sc.nextLine();
                    String hexInput = sc.nextLine();
                    System.out.println("Decimal value is : "+ toDecimal(hexInput));
                    break;
                default:
                    System.out.println("Exiting ...");
                    return;
            }
        }
    }
}