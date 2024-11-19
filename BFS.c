#include <stdio.h>
#include <stdlib.h>

int V, E, visited[20], G[20][20], Q[20], front = -1, rear = -1;

void enqueue(int item) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    Q[rear] = item;
}

int dequeue() {
    if (front == -1 && rear == -1) {
        return -1; 
    }
    int item = Q[front];
    if (front == rear) {
        front = rear = -1; 
    } else {
        front++;
    }
    return item;
}


void BFS(int s) {
    visited[s] = 1;
    printf("%d ", s);
    enqueue(s);
    while (front != -1) {
        s = dequeue();
        for (int i = 1; i <= V; i++) {
            if (G[s][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

void initializeGraph() {
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            G[i][j] = 0;
        }
    }
}

void resetVisited() {
    for (int i = 1; i <= V; i++) {
        visited[i] = 0;
    }
}

int main() {
    int v1, v2, source;

    printf("Enter the number of vertices of the graph: ");
    scanf("%d", &V);
   
    initializeGraph();

    printf("Enter the number of edges of the graph: ");
    scanf("%d", &E);
    for (int i = 1; i <= E; i++) {
        printf("Enter the edges (format: V1 V2): ");
        scanf("%d %d", &v1, &v2);
        if (v1 > 0 && v1 <= V && v2 > 0 && v2 <= V) { 
            G[v1][v2] = 1;
            G[v2][v1] = 1;
        } else {
            printf("Invalid edge (%d, %d)!\n", v1, v2);
            i--; 
        }
    }

    printf("\nThe adjacency matrix:\n");
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            printf("%d\t", G[i][j]);
        }
        printf("\n");
    }

    printf("Enter the source vertex for traversal: ");
    scanf("%d", &source);

    resetVisited();
    printf("\nBFS starting from vertex %d:\n", source);
    BFS(source);
   
    return 0;
}
