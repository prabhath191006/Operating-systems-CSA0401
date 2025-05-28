#include <stdio.h>
#include <stdlib.h>

int main() {
    int ReadyQueue[100], i, n, TotalHeadMov = 0, initial;

    // Input: Number of disk requests
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    // Input: The disk queue
    printf("Enter the disk queue: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &ReadyQueue[i]);
    }

    // Input: Initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    // FCFS disk scheduling calculation
    for(i = 0; i < n; i++) {
        TotalHeadMov += abs(ReadyQueue[i] - initial);
        initial = ReadyQueue[i];
    }

    // Output total head movement
    printf("Total Head Movement = %d\n", TotalHeadMov);

    return 0;
}
