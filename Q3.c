#include <stdio.h>
#include <stdlib.h>

// Function to allocate a 2D matrix
int** allocate_matrix(int N) {
    int** M = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        M[i] = (int*)malloc(N * sizeof(int));
    }
    return M;
}

// Function to free a 2D matrix
void free_matrix(int** M, int N) {
    for (int i = 0; i < N; i++) {
        free(M[i]);
    }
    free(M);
}

// Function to remove transitive edges
void remove_transitivity(int** M, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && M[i][j]) {
                for (int k = 0; k < N; k++) {
                    if (i != k && j != k && M[j][k] && M[i][k]) {
                        // i -> j and j -> k exist, and i -> k also exists => remove i -> k
                        M[i][k] = 0;
                    }
                }
            }
        }
    }
}

// Function to remove reflexive edges
void remove_reflexivity(int** M, int N) {
    for (int i = 0; i < N; i++) {
        M[i][i] = 0;
    }
}

// Function to print simplified graph (Hasse diagram edges)
void print_edges(int** M, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (M[i][j]) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    // Step 1: Input matrix
    int** M = allocate_matrix(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    // Step 2: Simplify the graph
    remove_transitivity(M, N);
    remove_reflexivity(M, N);

    // Step 3: Output simplified relation
    print_edges(M, N);

    // Step 4: Cleanup
    free_matrix(M, N);
    return 0;
}
