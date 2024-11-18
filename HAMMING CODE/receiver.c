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
    size = k ;

    // Create the message array
    int msg[size];

    // Get the message bits at non-redundant positions
    printf("Enter the message bits: ");
    for (int i = 0; i < size; i++) {
            scanf("%d", &msg[i]);
    }
    int red[r];
    // Calculate redundant bit values using XOR
    for (int i = 0; i < r; i++) {
        int pos = pow(2, i) - 1; // Position of the redundant bit
        int parity = 1;
        // Calculate the range of data bits covered by this redundant bit
        int start = pos + 1;
        int end = start + pow(2, i) - 1;
        // Calculate parity using XOR
        for (int j = start; j <= end && j < size; j++) {
            parity ^= msg[j];
        }
        red[i] = parity;
    }
    // Print the redundant bits
    int redundant=0;
    printf("redundant bits: ");
    for (int i = 0; i < r; i++) {
        printf("%d ", red[i]);
        redundant=redundant*10+red[i];
    }
    //calculate pos of error bit
    int rem=0,err=0,b=1;
    while(redundant>0){
        rem=redundant%10;
        err=err+rem*b;
        redundant/=10;
        b*=2;
    }
    if(err==0)
            printf("\nNo error");
    else
    printf("\nPosition of error Bit: %d",err);
    return 0;
}
