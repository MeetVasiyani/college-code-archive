import java.util.*;

class Node{
    int val;
    Node left,right;

    public Node(int data){
        val = data;
        left = right = null;
    }
}

class Main {
    public static Node insert(Node root,int data){
        if(root == null){
            return new Node(data);
        }
        else if(root.val < data){
            root.right = insert(root.right,data);
        }
        else{
            root.left = insert(root.left,data);
        }
        return root;
    }
    public static int inorder(Node root,int [] arr,int index){
        if(root == null) return index;

        index = inorder(root.left,arr,index);
        arr[index++] = root.val;
        index = inorder(root.right,arr,index);

        return index;
    }
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of array : ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        for(int i = 0; i < n; i++){
            System.out.println("Enter number for index " + (i+1) + " : ");
            arr[i] = sc.nextInt();
        }

        Node root = null;

        for(int i = 0; i < n; i++){
            root = insert(root,arr[i]);
        }

        inorder(root,arr,0);

        System.out.println("Array : ");
        
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+", ");
        }
    }
}

