import java.util.Stack;

public class Main {
    public static int performOperation(int op1,int op2,char ch){
        if(ch == '+') return op1 + op2;
        else if(ch == '-') return op1 - op2;
        else if(ch == '/') return op1 / op2;
        else return op1 * op2;
    }
    public static int evaluatePrefix(String exp) {
        int n = exp.length();
        Stack<Integer> stk = new Stack<>();
        for(int i = n-1; i >= 0 ; i--){
            char ch = exp.charAt(i);
            if(Character.isDigit(ch)){
                int temp = ch - '0';
                stk.push(temp);
            }
            else{
                int op1 = stk.pop();
                int op2 = stk.pop();
                int res = performOperation(op1,op2,ch);
                stk.push(res);
            }
        }
        return stk.pop();
    }

    public static void main(String[] args) {

        String expression = "+9*23";

        int result = evaluatePrefix(expression);

        System.out.println("Result = " + result);
    }
}