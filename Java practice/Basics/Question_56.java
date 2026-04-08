import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string : ");
        String s = sc.nextLine();

        int total0 = 0, total1 = 0;
        for(char ch : s.toCharArray()){
            if(ch == '0') total0++;
            else total1++;
        }

        int left0 = 0, right0 = total0;
        int left1 = 0, right1 = total1;
        int ans = 0;

        for(char c : s.toCharArray()){
            if(c == '0') right0--;
            else right1--;

            if(c == '0'){
                ans += left1 * right1;
            } else{
                ans += left0 * right0;
            }

            if(c == '0') left0++;
            else left1++;
        }

        System.out.println("Total Buildings : "+ans);
    }
}