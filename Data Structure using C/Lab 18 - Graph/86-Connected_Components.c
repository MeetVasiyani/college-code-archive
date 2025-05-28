/*
86. You are given an undirected graph with N nodes (numbered 1 through N).  
For each valid i, the i-th node has a weight Wi. Also, for each pair of nodes i and 
j, there is an edge connecting nodes if j – i ≠ Wj - Wi.  
 
Find the number of connected components in this graph. 
 
Input Format: 
• The first line of the input contains a single integer T denoting the number of 
test  cases. The description of T test cases follows. 
• The first line of each test case contains a single integer N. 
• The line contains N space-separated integers W1, W2, ..., WN. 
 
Output Format : 
 
For each test case, print a single line containing one integer --- the number of 
components in the graph. 
 
Sample Example: 
 
Input: 
 
2 
2 
1 2  
2 
2 1 
Output: 
 
2 
1 

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int node, int n) {
    visited[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int N, W[MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &N);

    printf("Enter weights of nodes:\n");
    for (int i = 1; i <= N; i++)
        scanf("%d", &W[i]);

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if ((j - i) != (W[j] - W[i])) {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }

    int components = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, N);
            components++;
        }
    }

    printf("Number of connected components: %d\n", components);
    return 0;
}
