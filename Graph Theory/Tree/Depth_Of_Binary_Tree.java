package Tree;

import java.util.LinkedList;
import java.util.Queue;

class Node {
    int data;
    Node left;
    Node right;

    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

public class Depth_Of_Binary_Tree {

    private static int Calculate_Depth_Recursive(Node root) {
        if (root == null) {
            return 0;
        }

        int l= Calculate_Depth_Recursive(root.left);
        int r = Calculate_Depth_Recursive(root.right);
        return Math.max(l, r) + 1;
    }

    private static int Calculate_Depth(Node root) {
        if (root == null) {
            return 0;
        }
        Queue<Node> queue = new LinkedList<>();
        int count = 0;
        queue.offer(root);
        while (!queue.isEmpty()) {
            int temp = queue.size();
            for (int i = 0; i < temp; i++) {
                Node currNode = queue.poll();
                if (currNode.left != null) {
                    queue.add(currNode.left);
                }
                if (currNode.right != null) {
                    queue.add(currNode.right);
                }
            }
            count++;
        }
        return count;
    }

    public static void main(String[] args) {
        Node root = new Node(5);
        root.left = new Node(10);
        root.right = new Node(20);
        root.right.left = new Node(30);
        root.right.right = new Node(40);
        int result = Calculate_Depth_Recursive(root);
        System.out.println("Depth of given Tree : " + result);
    }
}