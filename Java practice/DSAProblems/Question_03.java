import java.util.*;

class Node{
    int val;
    Node lptr,rptr;
    public Node(int val) {
        this.val = val;
        this.lptr = null;
        this.rptr = null;
    }
}

class Main{
    public static Node insertNode(Node root,int val){
        Node newNode = new Node(val);
        if(root == null){
            return newNode;
        }
        Node curr = root;
        while(curr.rptr != null){
            curr = curr.rptr;
        }
        curr.rptr = newNode;
        newNode.lptr = curr;
        return root;
    }

    public static void printList(Node root)
    {
        Node curr = root;
        while(curr != null){
            System.out.print(curr.val +"->");
            curr = curr.rptr;
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
            root = insertNode(root,temp);
        }
        printList(root);

        Node odd_head = null, even_head = null;
        Node odd_curr = null, even_curr = null;
        Node curr = root;

        while(curr != null){

            Node next = curr.rptr;
            curr.rptr = null;
            curr.lptr = null;
            
            if(curr.val % 2 == 0){
                if(even_head == null){
                    even_head = curr;
                    even_curr = curr;
                }
                else{
                    even_curr.rptr = curr;
                    curr.lptr = even_curr;
                    even_curr = curr;
                }
            }else{
                if(odd_head == null){
                    odd_head = curr;
                    odd_curr = curr;
                }
                else{
                    odd_curr.rptr = curr;
                    curr.lptr = odd_curr;
                    odd_curr = curr;
                }
            }
            curr = next;
        }

        System.out.println("Even List : ");
        printList(even_head);

        System.out.println("Odd List : ");
        printList(odd_head);
    }
}