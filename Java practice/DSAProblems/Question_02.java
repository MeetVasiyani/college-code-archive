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
    public static Node insertNode(Node root,Node newNode){
        if(root == null || newNode.val < root.val){
            newNode.next = root;
            return newNode;
        }
        Node curr = root;
        while(curr.next != null && curr.next.val < newNode.val){
            curr = curr.next;
        }

        newNode.next = curr.next;
        curr.next = newNode;
        return root;
    }

    public static void printList(Node root)
    {
        Node curr = root;
        while(curr != null){
            System.out.print(curr.val +"->");
            curr = curr.next;
        }
        System.out.println();
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Node root = null;

        System.out.println("Enter number of inputs : ");
        int n = sc.nextInt();

        for(int i = 0; i < n; i++){
            int temp = sc.nextInt();
            Node newNode = new Node(temp);
            root = insertNode(root,newNode);
        }
        printList(root);
    }
}