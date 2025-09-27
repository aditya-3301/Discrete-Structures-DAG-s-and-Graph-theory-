#include <stdio.h>
#include <stdlib.h>

void indegree(int** M, int N, int* in_degree) {
    for (int i = 0; i < N; i++) {
        in_degree[i] = 0;  // Reset in-degree for component i
        for (int j = 0; j < N; j++) {
            if (M[j][i] == 1) {
                in_degree[i]++;  // Increment in-degree for component i
            }
        }
    }
}

// Function to find a component with zero indegree and no other remaining dependencies
int isMinimal(int* in_degree, int N) {
    for (int i = 0; i < N; i++) {
        if (in_degree[i] == 0) {
            return i;  // Return the index of the component with zero indegree
        }
    }
    return -1;  // No component with zero indegree, should not happen in a valid DAG
}

// Recursive function to process the components in the correct build order
void order(int** M, int N, int* in_degree, int* processed) {
    int component = isMinimal(in_degree, N);
    if (component == -1) {
        return;  // No component with zero indegree left, we are done
    }

    printf("%d ", component);  // Print the component in build order
    in_degree[component] = -1;  // Mark this component as processed

    // Remove dependencies (set corresponding row in matrix to 0)
    for (int i = 0; i < N; i++) {
        if (M[component][i] == 1) {
            in_degree[i]--;  // Decrease the indegree of the dependent component
        }
    }

    // Recursive call to process the next component
    order(M, N, in_degree, processed);
}

int main() {
    int N;
    scanf("%d", &N);

    // Allocate memory for the matrix (adjacency matrix)
    int** M = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        M[i] = (int*)malloc(N * sizeof(int));
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &M[i][j]) == 1)
                count++;
        }
    }
    printf("Read %d numbers\n", count);


    // Allocate memory for in-degree array
    int* in_degree = (int*)malloc(N * sizeof(int));
    
    // Initialize in-degree values
    indegree(M, N, in_degree);

    // Call the order function to print the build order
    order(M, N, in_degree, NULL);

    // Clean up memory
    for (int i = 0; i < N; i++) {
        free(M[i]);
    }
    free(M);
    free(in_degree);

    return 0;
}
