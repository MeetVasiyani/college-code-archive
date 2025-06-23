import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class Breadth_First_Search {

    public static void bfs(int [][] adj,int source){
        HashSet<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        int [] result = new int[adj.length];
        int count = 0;
        
        queue.add(source);
        visited.add(source);

        while(!queue.isEmpty()){

            int temp = queue.poll();
            result[count++] = temp;
    
            for(int i = adj[temp].length-1; i >= 0; i--){
                if(!visited.contains(adj[temp][i])){
                    visited.add(adj[temp][i]);
                    queue.add(adj[temp][i]);
                }
            }
        }
        
        for (int i = 0; i < result.length; i++) {
            System.err.println(result[i]+" ");
        }
    }

    public static void main(String[] args) {
        int [][] adj = {{1,2},{0,2},{0,1,3,4},{2},{2}};
        bfs(adj,0);
    }
}
