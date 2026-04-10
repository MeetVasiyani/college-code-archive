import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter string: ");
        String str = sc.nextLine();

        Stack<Character> stack = new Stack<>();
        int i = 0;

        while(i < str.length() && str.charAt(i) != 'c'){
            char ch = str.charAt(i);
            stack.push(ch);
            i++;
        }

        i++;

        while(i < str.length()){
            if(stack.isEmpty() || stack.pop() != str.charAt(i)){
                System.out.println("String not accepted");
                return;
            }
            i++;
        }

        if(stack.isEmpty()){
            System.out.println("String accepted");
        }else{
            System.out.println("String not accepted");
        }
    }
}