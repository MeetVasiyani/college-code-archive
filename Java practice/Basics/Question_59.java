import java.util.*;

class Main{
    public static boolean validNumber(String s){
        boolean digitSeen = false;
        boolean dotSeen = false;
        boolean eSeen = false;

        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);

            if(Character.isDigit(ch)){
                digitSeen = true;
            }

            else if(ch == '+' || ch == '-'){
                if(i != 0 && s.charAt(i-1) != 'e' && s.charAt(i-1) != 'E'){
                    return false;
                }
            }

            else if(ch == '.'){
                if(dotSeen || eSeen) return false;
                dotSeen = true;
            }

            else if(ch == 'e' || ch == 'E'){
                if(eSeen || !digitSeen){
                    return false;
                }
                eSeen = true;
                digitSeen = false;
            }

            else{
                return false;
            }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string : ");
        String s = sc.nextLine();

        if(validNumber(s)){
            System.out.println("It is a valid number.");
        }else{
            System.out.println("It is a valid number.");
        }
        
        }
    }
}