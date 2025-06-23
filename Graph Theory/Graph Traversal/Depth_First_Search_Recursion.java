import java.util.HashSet;
import java.util.Stack;

public class Depth_First_Search_Recursion {
    public static void dfsrecursive(int [][]adj,Stack<Integer> stack, HashSet<Integer> visited,int source){
        
        stack.push(source);
        visited.add(source);
        int temp = stack.pop();
        System.out.println(temp+" ");

        for(int i = adj[temp].length-1; i >= 0; i--){
            if(!visited.contains(adj[temp][i])){
                dfsrecursive(adj, stack, visited, adj[temp][i]);
            }
        }
    }

    public static void startDFS(int [][] adj, int src){
        HashSet<Integer> visited = new HashSet<>();
        Stack<Integer> stack = new Stack<>();
        dfsrecursive(adj,stack,visited,src);
    }

    public static void main(String[] args) {
        int [][] adj = {{1,2},{0,2},{0,1,3,4},{2},{2}};
        startDFS(adj,0);
    }
}
