import java.util.*;

class StackUsingQueues {
    Queue<Integer> q1 = new LinkedList<>();
    Queue<Integer> q2 = new LinkedList<>();

    void push(int x) {
        q1.add(x);
    }

    int pop() {
        if (q1.isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }

        while (q1.size() > 1) {
            q2.add(q1.remove());
        }

        int popped = q1.remove();

        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;

        return popped;
    }

    int peek() {
        if (q1.isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }

        while (q1.size() > 1) {
            q2.add(q1.remove());
        }

        int top = q1.remove();
        q2.add(top);

        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;

        return top;
    }

    // Check empty
    boolean isEmpty() {
        return q1.isEmpty();
    }

    public static void main(String[] args) {
        StackUsingQueues s = new StackUsingQueues();

        s.push(10);
        s.push(20);
        s.push(30);

        System.out.println("Popped: " + s.pop());
        System.out.println("Top: " + s.peek());
    }
}