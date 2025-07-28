import java.util.Arrays;

public class Kruskals_Algorithm {
    static int [] parent;

    public static void main(String[] args) {
        int V = 4,totalweight = 0;
        parent = new int[V];
        int [][] inputEdges = {
            {0,1,10},
            {0,2,6},
            {0,3,5},
            {1,3,15},
            {2,3,4}
        };
        Arrays.sort(inputEdges,(a,b)->a[2]-b[2]);
        for(int i=0; i < V; i++){
            parent[i] = i;
        }
        for(int i = 0; i < V;i++){
            int src = inputEdges[i][0];
            int dest = inputEdges[i][1];
            int weight = inputEdges[i][2];

            if(find(src) != find(dest)){
                union(src,dest);
                totalweight += weight;
            }
        }
        System.out.println("Total Traversal Weight : "+totalweight);
    }

    static int find(int i){
        if(parent[i] == i){
            return i;
        }
        return find(parent[i]);
    }

    static void union(int src,int dest){
        parent[find(dest)] = find(src);
    }
}