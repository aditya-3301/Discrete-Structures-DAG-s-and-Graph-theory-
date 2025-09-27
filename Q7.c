#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; // No of servers
    scanf("%d", &N);
    int M;
    scanf("%d", &M);

    int** A = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        A[i] = (int*)malloc(N * sizeof(int));
    }

    // Initialize array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 0;
        }
    }

    int a = 0;
    int b = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d", &a);
        scanf("%d", &b);
        A[a][b] = 1;
        A[b][a] = 1;
    }

    // (Optional) print adjacency matrix (comment out if not needed)
    
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }


    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = -1;
    }

    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp = A[i][j];
            if (temp && i != j) {
                for (int k = 0; k < N; k++) {
                    if (A[j][k] && j != k) {
                        if (A[k][i] && k != i) {
                            arr[i] = 1;
                            arr[j] = 1;
                            arr[k] = 1;
                        }
                    }
                }
            }
        }
    }
    printf("\n\n");

    // ✅ Updated output logic starts here
    int found = 0;

    for (int i = 0; i < N; i++) {
        int degree = 0;
        for (int j = 0; j < N; j++) {
            degree = degree+A[i][j];
        }

        if (arr[i] == -1 && degree > 0) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("-1");
    }

    // Optional: Free memory
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}
