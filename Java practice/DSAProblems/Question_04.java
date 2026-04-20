import java.util.*;

class Node{
    int val;
    Node next;

    public Node(int val){
        this.val = val;
        this.next = null;
    }
}

class Main{

    public static Node insertNode(Node root, Node newNode){
        if(root == null){
            return newNode;
        }

        Node curr = root;
        while(curr.next != null){
            curr = curr.next;
        }

        curr.next = newNode;
        return root;
    }

    public static Node addTwoNumbers(Node l1, Node l2){

        Node head = null;

        int carry = 0;
        while(l1 != null || l2 != null || carry > 0){
            int sum = carry;

            if(l1 != null){
                sum += l1.val;
                l1 = l1.next;
            }

            if(l2 != null){
                sum += l2.val;
                l2 = l2.next;
            }

            carry = sum/10;
            int digit = sum % 10;
            head = insertNode(head,new Node(digit));
        }
        return head;
    }

    public static void printList(Node root){
        Node curr = root;
        while(curr != null){
            System.out.print(curr.val + "->");
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        Node l1 = null;
        Node l2 = null;

        System.out.println("Enter size of first list:");
        int n1 = sc.nextInt();

        System.out.println("Enter elements:");
        for(int i = 0; i < n1; i++){
            int val = sc.nextInt();
            l1 = insertNode(l1, new Node(val));
        }

        System.out.println("Enter size of second list:");
        int n2 = sc.nextInt();

        System.out.println("Enter elements:");
        for(int i = 0; i < n2; i++){
            int val = sc.nextInt();
            l2 = insertNode(l2, new Node(val));
        }

        Node result = addTwoNumbers(l1, l2);

        System.out.println("Result List:");
        printList(result);

    }
}