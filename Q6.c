#include <stdio.h>
#include <string.h>

unsigned short swap_bytes(unsigned short val) {
    return (val << 8) | (val >> 8);
}

unsigned short rotate_left(unsigned short val, int k) {
    return (val << k) | (val >> (16 - k));
}

unsigned short flip_n(unsigned short val, int k) {
    return val ^ (1 << k);
}

unsigned short xor_mask(unsigned short val, unsigned short mask) {
    return val ^ mask;
}

int main() {
    unsigned short state;
    int T;

    // Read the initial value and number of transformations
    scanf("%hu", &state);
    scanf("%d", &T);

    // Since we need to apply transformations from RIGHT to LEFT,
    // we will store them and apply them in reverse later.
    char ops[T][20];
    int vals[T];        // For parameters (if any), otherwise -1
    for (int i = 0; i < T; ++i) {
        scanf("%s", ops[i]);

        // Check if the transformation needs a value
        if (strcmp(ops[i], "ROTATE_L") == 0 ||
            strcmp(ops[i], "FLIP_N") == 0 ||
            strcmp(ops[i], "XOR_MASK") == 0) {
            scanf("%d", &vals[i]);
        } else {
            vals[i] = -1; // No parameter
        }
    }

    // Apply transformations from right to left
    for (int i = T - 1; i >= 0; --i) {
        if (strcmp(ops[i], "SWAP_BYTES") == 0) {
            state = swap_bytes(state);
        } else if (strcmp(ops[i], "ROTATE_L") == 0) {
            state = rotate_left(state, vals[i]);
        } else if (strcmp(ops[i], "FLIP_N") == 0) {
            state = flip_n(state, vals[i]);
        } else if (strcmp(ops[i], "XOR_MASK") == 0) {
            state = xor_mask(state, vals[i]);
        }
    }

    printf("%hu\n", state);
    return 0;
}
