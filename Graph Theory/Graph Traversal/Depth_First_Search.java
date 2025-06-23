import java.util.HashSet;
import java.util.Stack;

class Depth_First_Search{

    public static void dfs(int [][] adj,int source){
        HashSet<Integer> visited = new HashSet<>();
        Stack<Integer> stack = new Stack<>();
        int [] result = new int[adj.length];
        int count = 0;
        stack.push(source);
        visited.add(source);

        while (!stack.empty()) {
            int temp = stack.pop();
            result[count++] = temp;
            
            for(int i = adj[temp].length-1; i >= 0; i--){
                if(!visited.contains(adj[temp][i])){
                    visited.add(adj[temp][i]);
                    stack.push(adj[temp][i]);
                }
            }
        }
        for (int i = 0; i < result.length; i++) {
            System.err.println(result[i]+" ");
        }
    }

    public static void main(String[] args) {
        int [][] adj = {{1,2},{0,2},{0,1,3,4},{2},{2}};
        dfs(adj,0);
    }
}
