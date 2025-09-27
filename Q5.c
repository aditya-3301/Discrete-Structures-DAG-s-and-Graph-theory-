#include <stdio.h>
#include <stdlib.h>

void LBS(int** M, int N, int* arr, int a, int b) {
    int i = 0;
    for (int z = 0; z < N; z++) {
        if (M[z][a] && M[z][b] && i < N) {
            arr[i] = z;
            i++;
        }
    }
}

void UBS(int** M, int N, int* arr1, int a, int b){
    int i = 0;
    for (int z = 0; z < N; z++) {
        if (M[a][z] && M[b][z] && i < N) {
            arr1[i] = z;
            i++;
        }
    }
}

int max(int* arr, int N) {
    int max = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int min(int* arr, int N) {
    int min = 1000000000;  // Use an int-safe large value
    for (int i = 0; i < N; i++) {
        if (arr[i] < min && arr[i] != -1)
            min = arr[i];
    }
    return min;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("Matrix size: %d\n", N);

    int** M = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        M[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    while(getchar() != '\n');  // Clear the input buffer

    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        arr[i] = -1;
    }
    int* arr1 = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        arr1[i] = 100000000;
    }
    int a, b;
    printf("Enter a and b for LUB/GLB of a,b: ");
    scanf("%d", &a);
    scanf("%d", &b);

    printf("a = %d, b = %d\n", a, b);

    LBS(M, N, arr, a, b);
    printf("GLB: %d\n", max(arr, N));
    UBS(M, N, arr1, a, b);
    printf("LUB: %d\n", min(arr1, N));

    for (int i = 0; i < N; i++) {
        free(M[i]);
    }
    free(M);
    free(arr);
    free(arr1);

    return 0;
}
