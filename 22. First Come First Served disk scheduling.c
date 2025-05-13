#include <stdio.h>
#include <stdlib.h> // For abs()

int main() {
    int n, i, totalHeadMovement = 0, head;

    printf("Enter the number of disk I/O requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the disk I/O request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int current = head;
    printf("\nServicing Order:\n");

    for(i = 0; i < n; i++) {
        printf("Move from %d to %d\n", current, requests[i]);
        totalHeadMovement += abs(requests[i] - current);
        current = requests[i];
    }

    printf("\nTotal head movement = %d\n", totalHeadMovement);

    return 0;
}
