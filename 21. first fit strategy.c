#include <stdio.h>

int main() {
    int blockSize[10], processSize[10], blockAllocated[10];
    int i, j, numBlocks, numProcesses;

    printf("Enter number of memory blocks: ");
    scanf("%d", &numBlocks);

    printf("Enter size of each memory block:\n");
    for (i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter size of each process:\n");
    for (i = 0; i < numProcesses; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        blockAllocated[i] = -1; // initially not allocated
    }

    for (i = 0; i < numProcesses; i++) {
        for (j = 0; j < numBlocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                blockAllocated[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock Allocated\n");
    for (i = 0; i < numProcesses; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (blockAllocated[i] != -1)
            printf("%d\n", blockAllocated[i] + 1); // block number
        else
            printf("Not Allocated\n");
    }

    return 0;
}
