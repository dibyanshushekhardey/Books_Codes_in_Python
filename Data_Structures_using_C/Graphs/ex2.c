#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Function to perform depth-first search (DFS)
bool dfs(int adjacencyMatrix[][MAX_VERTICES], int numVertices, int source, int destination, bool visited[]) {
    if (source == destination) {
        return true; // Path from source to destination found
    }

    visited[source] = true;

    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[source][i] == 1 && !visited[i]) {
            if (dfs(adjacencyMatrix, numVertices, i, destination, visited)) {
                return true; // Path from source to destination found
            }
        }
    }

    return false; // No path from source to destination
}

int main() {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices, source, destination;

    printf("Enter the number of vertices in the graph (maximum 10): ");
    scanf("%d", &numVertices);

    if (numVertices <= 0 || numVertices > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 0;
    }

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    if (source < 0 || source >= numVertices || destination < 0 || destination >= numVertices) {
        printf("Invalid source or destination vertex.\n");
        return 0;
    }

    bool visited[MAX_VERTICES] = { false };

    bool pathExists = dfs(adjacencyMatrix, numVertices, source, destination, visited);

    if (pathExists) {
        printf("There is at least one path from the source to the destination.\n");
    } else {
        printf("There is no path from the source to the destination.\n");
    }

    return 0;
}
