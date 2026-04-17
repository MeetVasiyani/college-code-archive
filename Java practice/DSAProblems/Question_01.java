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

    public static Node sortList(Node root){
        if(root == null || root.next == null){
            return root;
        }
        
        for(Node i = root; i != null; i = i.next){
            for(Node j = i.next; j != null; j = j.next){
                if(i.val > j.val){
                    int temp = i.val;
                    i.val = j.val;
                    j.val = temp;
                }
            }
        }
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
        sortList(root);
        printList(root);
    }
}