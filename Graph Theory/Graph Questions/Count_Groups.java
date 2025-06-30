import java.util.HashSet;
import java.util.Stack;

public class Count_Groups {

    public static void dfsrecursive(int [][]adj,Stack<Integer> stack, HashSet<Integer> visited,int source){
        
        stack.push(source);
        visited.add(source);
        int temp = stack.pop();

        for(int i = adj[temp].length-1; i >= 0; i--){
            if(!visited.contains(i) && adj[temp][i] == 1){
                dfsrecursive(adj, stack, visited, i);
            }
        }
    }

    public static int countGroups(int [][] adj,int src){
        HashSet<Integer> visited = new HashSet<>();
        Stack<Integer> stack = new Stack<>();
        int count = 0;
        for (int i = 0; i < adj.length; i++) {
            for (int j = 0; j < adj[i].length; j++) {
                if(!visited.contains(j) && adj[i][j] == 1){
                    dfsrecursive(adj, stack, visited, j);
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int [][] adj = {{1,1,1,1},{1,1,1,1},{0,0,1,1},{0,0,1,1}};
        int groups = countGroups(adj,0);
        System.out.println("Total Groups : "+groups);
    }
}
