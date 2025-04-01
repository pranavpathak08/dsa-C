// Graph Implementation in C using Adjacency Matrix

#include <stdio.h>
#include <stdlib.h>

#define V 5  

void init(int arr[V][V]) {
    int i, j;
    for (i = 0; i < V; i++) {  
        for (j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int arr[V][V], int src, int dest) {
    if (src >= 0 && src < V && dest >= 0 && dest < V) { 
        arr[src][dest] = 1;
        arr[dest][src] = 1;  
    } else {
        printf("Invalid edge: (%d, %d)\n", src, dest);
    }
}

void printAdjMatrix(int arr[V][V]) {
    int i, j;
    for (i = 0; i < V; i++) { 
        for (j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[V][V];

    init(adjMatrix);
    printf("Initial Graph:\n");
    printAdjMatrix(adjMatrix);

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    printf("\nGraph after adding edges:\n");
    printAdjMatrix(adjMatrix);

    return 0;
}
