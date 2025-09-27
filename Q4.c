#include <stdio.h>
#include <stdlib.h>

// Function to count number of set bits in x
int count_bits(int x) {
    int count = 0;
    while (x) {
        count = count + (x & 1);  // Add 1 if least significant bit is set
        x >>= 1;                  // Shift right to check next bit
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    // Allocate N x N matrix M
    int** M = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        M[i] = (int*)malloc(N * sizeof(int));
    }

    // Read the surveillance matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    // Build coverage array: coverage[i] is bitmask of locations tower i can see
    int* coverage = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        coverage[i] = 0;
        for (int j = 0; j < N; j++) {
            if (M[i][j] == 1) {
                coverage[i] |= (1 << j);
            }
        }
    }

    int full_coverage = (1 << N) - 1;  // Bitmask where all N bits are set (all locations covered)
    int min_towers = N + 1;             // Start with max possible + 1

    // Iterate over all subsets of towers (from 1 to 2^N - 1)
    for (int subset = 1; subset < (1 << N); subset++) {
        int combined_coverage = 0;
        // For each tower, check if it's in the current subset
        for (int tower = 0; tower < N; tower++) {
            if (subset & (1 << tower)) {
                combined_coverage |= coverage[tower];  // Add coverage of this tower
            }
        }
        // Check if this subset covers all locations
        if (combined_coverage == full_coverage) {
            int towers_used = count_bits(subset);
            if (towers_used < min_towers) {
                min_towers = towers_used;
            }
        }
    }

    // Output the minimum number of towers needed
    printf("%d\n", min_towers);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(M[i]);
    }
    free(M);
    free(coverage);

    return 0;
}
