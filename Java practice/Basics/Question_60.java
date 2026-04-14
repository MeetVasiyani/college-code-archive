import java.util.*;
class Main{
    public static String decodeString(String str){
        StringBuilder sb = new StringBuilder();
        int n = str.length();
        int i = 0;
        while(i < n){
            if(Character.isDigit(str.charAt(i))){
                int num = 0;
                while(i < n && Character.isDigit(str.charAt(i))){
                    num = num * 10 + (str.charAt(i) - '0');
                    i++;
                }

                if(i < n){
                    char ch = str.charAt(i);
                    for(int j = 0; j < num; j++){
                        sb.append(ch);
                    }
                }
            }
            else{
                sb.append(str.charAt(i));
            }
            i++;
        }

        return sb.toString();
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string: ");
        String input = sc.nextLine();

        String result = decodeString(input);

        System.out.println("Decoded String : "+result);

        sc.close();
    }
}