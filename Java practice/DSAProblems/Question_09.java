import java.util.*;

public class BasicCalculator {

    public static int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    public static int applyOperation(int a, int b, char op) {

        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }

        return 0;
    }

    public static int evaluate(String s) {

        Stack<Integer> numbers = new Stack<>();
        Stack<Character> operators = new Stack<>();

        for (int i = 0; i < s.length(); i++) {

            char ch = s.charAt(i);

            if (ch == ' ')
                continue;

            if (Character.isDigit(ch)) {

                int num = 0;

                while (i < s.length() && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + (s.charAt(i) - '0');
                    i++;
                }

                numbers.push(num);
                i--;
            }

            else if (ch == '(') {
                operators.push(ch);
            }

            else if (ch == ')') {

                while (operators.peek() != '(') {
                    int b = numbers.pop();
                    int a = numbers.pop();
                    char op = operators.pop();

                    numbers.push(applyOperation(a, b, op));
                }

                operators.pop();
            }

            else {

                while (!operators.isEmpty() &&
                        precedence(operators.peek()) >= precedence(ch)) {

                    int b = numbers.pop();
                    int a = numbers.pop();
                    char op = operators.pop();

                    numbers.push(applyOperation(a, b, op));
                }

                operators.push(ch);
            }
        }

        while (!operators.isEmpty()) {

            int b = numbers.pop();
            int a = numbers.pop();
            char op = operators.pop();

            numbers.push(applyOperation(a, b, op));
        }

        return numbers.pop();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter expression: ");
        String expression = sc.nextLine();

        int result = evaluate(expression);

        System.out.println("Result = " + result);
    }
}