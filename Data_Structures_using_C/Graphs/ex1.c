#include <stdio.h>

#define MAX_VERTICES 10

// Function to create a graph
void createGraph(int adjacencyMatrix[][MAX_VERTICES], int numVertices) {
    int i, j;

    // Initialize the adjacency matrix with zeros
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    // Set the edges in the graph
    // For simplicity, we use a hardcoded example here
    adjacencyMatrix[0][1] = 1;
    adjacencyMatrix[0][2] = 1;
    adjacencyMatrix[1][3] = 1;
    adjacencyMatrix[1][4] = 1;
    adjacencyMatrix[2][4] = 1;
    adjacencyMatrix[3][4] = 1;
    adjacencyMatrix[3][5] = 1;
    adjacencyMatrix[4][5] = 1;
    adjacencyMatrix[4][6] = 1;
}

// Function to print the graph
void printGraph(int adjacencyMatrix[][MAX_VERTICES], int numVertices) {
    int i, j;

    printf("Graph Adjacency Matrix:\n");

    // Print the column indices
    printf("   ");
    for (i = 0; i < numVertices; i++) {
        printf("%d  ", i);
    }
    printf("\n");

    // Print the rows with their corresponding values
    for (i = 0; i < numVertices; i++) {
        printf("%d  ", i);
        for (j = 0; j < numVertices; j++) {
            printf("%d  ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

    printf("Enter the number of vertices in the graph (maximum 10): ");
    scanf("%d", &numVertices);

    createGraph(adjacencyMatrix, numVertices);
    printGraph(adjacencyMatrix, numVertices);

    return 0;
}
