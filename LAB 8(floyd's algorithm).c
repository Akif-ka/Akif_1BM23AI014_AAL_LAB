#include <stdio.h>
#define V 4
#define INF 99999
void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int graph[V][V] = {
        {0,   13,  INF, 10},
        {INF, 5,   6, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };
    floydWarshall(graph);
    return 0;
}


OUTPUT:
Shortest distances between every pair of vertices:
      0     13     19     10
    INF      5      6      7
    INF    INF      0      1
    INF    INF    INF      0
