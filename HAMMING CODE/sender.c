#include <stdio.h>
#include <math.h>

int main() {
    int k, r = 0, size;
    printf("Enter the size of message: ");
    scanf("%d", &k);

    // Calculate the number of redundant bits
    while (pow(2, r) < k + r + 1) {
        r++;
    }
    size = k + r;

    // Create the message array
    int msg[size];

    // Initialize the message with 0s
    for (int i = 0; i < size; i++) {
        msg[i] = 0;
    }

    // Get the message bits at non-redundant positions
    printf("Enter the message bits: ");
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i == pow(2, j) - 1) {
            j++;
        } else {
            scanf("%d", &msg[i]);
        }
    }
    // Calculate redundant bit values using XOR
    for (int i = 0; i < r; i++) {
        int pos = pow(2, i) - 1; // Position of the redundant bit
        int parity = 0;
        // Calculate the range of data bits covered by this redundant bit
        int start = pos + 1;
        int end = start + pow(2, i) - 1;
        // Calculate parity using XOR
        for (int j = start; j <= end && j < size; j++) {
            parity ^= msg[j];
        }
        msg[pos] = parity;
    }
    // Print the full message with redundant bits
    printf("Message with redundant bits: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", msg[i]);
    }
    return 0;
}
