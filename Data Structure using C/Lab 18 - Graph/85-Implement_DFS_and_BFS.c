/*85. Write a program to apply DFS & BFS for a graph. */
#include <stdio.h>
#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX], front = 0, rear = 0;

void DFS(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            DFS(i, n);
    }
}

void BFS(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    front = rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, edges, u, v;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("DFS starting from vertex 0:\n");
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(0, n);

    printf("\nBFS starting from vertex 0:\n");
    BFS(0, n);

    return 0;
}
