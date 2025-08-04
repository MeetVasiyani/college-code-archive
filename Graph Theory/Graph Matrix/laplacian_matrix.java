package Matrix;

import java.util.Scanner;

public class laplacian_matrix {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes : ");
        int n = sc.nextInt();
        System.out.print("Enter number of edges : ");
        int e = sc.nextInt();
        int [][] edges = new int[e][2];


        for (int i = 0; i < e; i++) {
            System.out.print("Enter starting node of edge "+(i+1)+" : ");
            edges[i][0] = sc.nextInt();
            System.out.print("Enter ending node of edge "+(i+1)+" : ");
            edges[i][1] = sc.nextInt();
        }

        System.out.print("Edges : {");
        for (int i = 0; i < e; i++) {
            System.out.print("{"+edges[i][0]+","+edges[i][1]+"}");
        }
        System.out.print("}");

        int [][] adj = new int[n][n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adj[i][j] = 0;
            }
        }

        for(int i = 0; i < e; i++){
            adj[edges[i][0]-1][edges[i][1]-1] = 1;
            adj[edges[i][1]-1][edges[i][0]-1] = 1;
        }

        System.out.println("\nAdjacency Matrix :");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                System.out.print(adj[i][j]+"  ");
            }
            System.out.println();
        }

        int [][] deg = new int[n][n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                deg[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++){
            int temp = 0;
            for(int j = 0; j < n; j++){
                temp += adj[i][j];
            }
            deg[i][i] = temp;
        }

        System.out.println("Degree Matrix :");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                System.out.print(deg[i][j]+" ");
            }
            System.out.println();
        }

        int [][] lap = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                lap[i][j] = deg[i][j] - adj[i][j];
            }
        }

        System.out.println("Laplacian Matrix :");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                System.out.print(lap[i][j]+" ");
            }
            System.out.println();
        }
    }
}