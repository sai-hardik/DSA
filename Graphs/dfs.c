#include <stdio.h>
#include <stdlib.h>

/* Directed graph */

typedef struct graph {
    int n; /* Number of vertices in graph */
    int adj[10][10]; /* Adjacency matrix */
} Graph;

void create_graph(Graph*);
void display(Graph*);
void dfs(Graph*);
void dfs_helper(Graph*, int, int*);

int main() {

    Graph adj_mat;

    int ch;

    printf("Enter the number of vertices: ");
    scanf_s("%d", &adj_mat.n);

    create_graph(&adj_mat);

    do {

        printf("\n\nMAIN MENU\n");
        printf("1. Display matrix\n");
        printf("2. DFS traversal\n");
        printf("3. Exit\n");

        scanf_s("%d", &ch);

        switch(ch){
            case 1: {
                display(&adj_mat);
                break;
            }
            case 2: {
                dfs(&adj_mat);
                break;
            }
            case 3: {
                return 0;
            }
        }


    } while (1);

    return 0;
}
void create_graph(Graph* adj_mat) {
    int i, j;

     for (int i = 0; i < adj_mat->n; ++i) {
        for (int j = 0; j < adj_mat->n; ++j) {
            adj_mat->adj[i][j] = 0;
        }
    }

    while (1) {
        printf("Enter source and destination vertices: ");
        scanf_s("%d %d", &i, &j);

        if (i < 0 && j <= 0 || i >= adj_mat->n || j >= adj_mat->n) {
            break;
        }

        adj_mat->adj[i][j] = 1;
    }
}

void display(Graph* adj_mat) {
    for (int i = 0; i < adj_mat->n; ++i) {
        for (int j = 0; j < adj_mat->n; ++j) {
            printf("%d ", adj_mat->adj[i][j]);
        }
        printf("\n");
    }
}

void dfs(Graph* adj_mat) {
    int vertex, * visited;

    // Accept user input 
    printf("Enter source vertex: ");
    scanf_s("%d", &vertex);

    // Initialise visited list and set to 0s
    visited = (int*)calloc(adj_mat->n, sizeof(int));

    // Out of bounds
    if (vertex < 0 || vertex >= adj_mat->n) {
        printf("Vertex not in graph.\n");
        return;
    }

    // Call recursive function
    dfs_helper(adj_mat, vertex, visited);
    printf("\n");

    // Free memory used by visited
    free(visited);
}

void dfs_helper(Graph* adj_mat, int vertex, int* visited) {
    // Mark node as visited and display
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Call dfs_helper on all of its unvisited connections
    for (int i = 0; i < adj_mat->n; ++i) {
        if (adj_mat->adj[vertex][i] == 1 && visited[i] == 0) {
            dfs_helper(adj_mat, i, visited);
        }
    }
}
