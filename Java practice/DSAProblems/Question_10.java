class Node{
    int val;
    Node left;
    Node right;
    public Node(int val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class Main{
    public static Node insertNode(Node root,int val){
        if(root == null){
            return new Node(val);
        }
        if(val < root.val){
            root.left = insertNode(root.left,val);
        }
        else{
            root.right = insertNode(root.right,val);
        }
        return root;
    }
    public static void printLeafNodes(Node root){
        if(root == null){
            return;
        }

        if(root.left == null && root.right == null){
            System.out.print(root.val + " ");
        }

        printLeafNodes(root.left);
        printLeafNodes(root.right);
    }
    public static void main(String[] args){
        Node root = null;

        root = insertNode(root, 10);
        root = insertNode(root, 5);
        root = insertNode(root, 15);
        root = insertNode(root, 2);
        root = insertNode(root, 7);
        root = insertNode(root, 20);

        printLeafNodes(root);
    }
}