import java.util.*;

class QueueUsingStacks {
    Stack<Integer> s1 = new Stack<>();
    Stack<Integer> s2 = new Stack<>();

    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s1.isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }

        while (s1.size() > 1) {
            s2.push(s1.pop());
        }

        int popped = s1.pop();

        Stack<Integer> temp = s1;
        s1 = s2;
        s2 = temp;

        return popped;
    }

    int peek() {
        if (s1.isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }

        while (s1.size() > 1) {
            s2.push(s1.pop());
        }

        int top = s1.peek();
        s2.push(top);

        Stack<Integer> temp = s1;
        s1 = s2;
        s2 = temp;

        return top;
    }

    boolean isEmpty() {
        return s1.isEmpty();
    }

    public static void main(String[] args) {
        QueueUsingStacks q = new QueueUsingStacks();

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        System.out.println("Popped: " + q.dequeue());
        System.out.println("Front: " + q.peek());
    }
}