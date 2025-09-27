#include <stdio.h>
#include <stdlib.h>

void degree(int** M, int N, int* arr) {
    for (int i = 0; i < N; i++) {
        arr[i] = 0;
        for (int j = 0; j < N; j++) {
            if (M[i][j])
                arr[i]++;
        }
    }
}

void removealliance(int** M, int N, int* arr) {
    int* to_remove = (int*)malloc(N * sizeof(int));
    int flag = 0;

    // Mark all nodes with degree 1
    for (int i = 0; i < N; i++) {
        if(arr[i] == 1){
            to_remove[i]=1;
        }
        if (to_remove[i])
            flag = 1;
    }

    // If no nodes to remove, stop
    if (!flag) {
        free(to_remove);
        return;
    }

    // Remove edges for degree-1 nodes
    for (int i = 0; i < N; i++) {
        if (to_remove[i]) {
            for (int j = 0; j < N; j++) {
                if (M[i][j]) {
                    M[i][j] = 0;
                    M[j][i] = 0;
                }
            }
        }
    }

    free(to_remove);

    // Recompute degrees and recurse
    degree(M, N, arr);
    removealliance(M, N, arr);
}

int main() {
    int A, B, n;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &n);

    int N = A + B;

    // Allocate memory for adjacency matrix
    int** M = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        M[i] = (int*)malloc(N * sizeof(int));
    }

    // Allocate and initialize degree array
    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        arr[i] = 0;
    }

    // Initialize adjacency matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            M[i][j] = 0;
        }
    }

    // Read edges
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        M[a][b] = 1;
        M[b][a] = 1;
    }

    // Process graph
    degree(M, N, arr);
    removealliance(M, N, arr);

    // Count remaining edges
    int c = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (M[i][j])
                c++;
        }
    }

    printf("%d", c);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(M[i]);
    }
    free(M);
    free(arr);

    return 0;
}
