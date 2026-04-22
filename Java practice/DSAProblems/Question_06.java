import java.util.*;
class Main{
    public static int precedence(char ch){
        if(ch == '^') return 3;
        else if(ch == '*' || ch == '/') return 2;
        else if(ch == '+' || ch == '-') return 1;
        else return -1;
    }
    public static String infixToPostfix(String exp){
        String res = "";
        Stack<Character> stk = new Stack<>();

        int n = exp.length();

        for(int i = 0; i < n; i++){
            char ch = exp.charAt(i);

            if(Character.isLetterOrDigit(ch)){
                res += ch;
            }

            else if(ch == '('){
                stk.push(ch);
            }

            else if(ch == ')'){
                while(!stk.isEmpty() && stk.peek() != '('){
                    res += stk.pop();
                }
                stk.pop();
            }

            else{
                while(!stk.isEmpty() && precedence(ch) <= precedence(stk.peek())){
                    res += stk.pop();
                }
                stk.push(ch);
            }
        }
        
        while(!stk.isEmpty()){
            res += stk.pop();
        }

        return res;
    }
    public static void main(String[] args){
        String exp = "(A+B)*C";
        System.out.println("Infix Expression: " + exp);
        System.out.println("Postfix Expression: " + infixToPostfix(exp));
    }
}