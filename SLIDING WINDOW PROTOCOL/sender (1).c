#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SEQ 7
#define BUFFER ((MAX_SEQ + 1) / 2)

struct frame {
    int seq_no;
    int ack_no;
    char info;
};

struct frame s;

void send_frame(int frame_no, int frame_expected, char buff[], int message_length) {
    // Collect the data and print it
    s.seq_no = frame_no;
    s.ack_no = (frame_expected + MAX_SEQ) % (MAX_SEQ + 1);
    s.info = buff[frame_no % BUFFER];

    // Handle wrapping around for messages longer than buffer
    if (frame_no >= message_length) {
        printf("Reached end of message, stopping transmission.\n");
        return;
    }

    printf("Sending Frame %d: seq_no: %d, ack_no: %d, info: %c\n", frame_no, s.seq_no, s.ack_no, s.info);

}

int main() {
    int next_frame_to_send = 0;
    int ack_expected = 0;
    char out[BUFFER];
    int message_length;

    // Get the message
    printf("Enter the message: ");
    scanf("%s", out);
    message_length = strlen(out);

    // Handle buffer size mismatch (optional)
    if (message_length > BUFFER) {
        printf("Warning: Message length (%d) exceeds buffer size (%d). "
               "Some characters may be dropped.\n", message_length, BUFFER);
    }

    // Send each character in the message, wrapping around as needed
    for (int i = 0; i < message_length; i++) {
        send_frame(next_frame_to_send, ack_expected, out, message_length);
        next_frame_to_send = (next_frame_to_send + 1) % (MAX_SEQ + 1);
    }
    printf("\nAll frames Sent...Transmission Completed!");
    return 0;
}
