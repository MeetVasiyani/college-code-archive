import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string : ");
        String s = sc.nextLine();

        StringBuilder str = new StringBuilder(s);

        int left = 0, right = str.length()-1;

        while(left < right){
            char leftChar = str.charAt(left);
            char rightChar = str.charAt(right);

            if(!Character.isLetter(leftChar)){
                left++;
            }
            else if(!Character.isLetter(rightChar)){
                right--;
            }
            else{
                char temp = leftChar;
                str.setCharAt(left,rightChar);
                str.setCharAt(right,temp);

                left++;
                right--;
            }
        }

        System.out.println("Output: " + str.toString());

    }
}