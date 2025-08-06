#include <stdio.h>

#define V 5
int visited[V] = {0};

void dfs(int graph[V][V], int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {
        if (graph[v][i] != 0 && visited[i] == 0) {
            dfs(graph, i);
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

    printf("DFS Traversal: ");
    dfs(graph, 0);
    printf("\n");

    return 0;
}
