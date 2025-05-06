#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_BLOCKS 50

typedef struct {
    char name[20];
    int startBlock;
    int length;
} File;

int main() {
    File files[MAX_FILES];
    int memory[MAX_BLOCKS] = {0}; // 0 = free, 1 = occupied
    int fileCount = 0;

    int choice;
    do {
        printf("\n--- Sequential File Allocation ---\n");
        printf("1. Add File\n2. View Files\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (fileCount >= MAX_FILES) {
                printf("File limit reached!\n");
                continue;
            }

            char fileName[20];
            int start, len;

            printf("Enter file name: ");
            scanf("%s", fileName);
            printf("Enter starting block (0 - %d): ", MAX_BLOCKS - 1);
            scanf("%d", &start);
            printf("Enter file length (in blocks): ");
            scanf("%d", &len);

            // Check if within bounds
            if (start < 0 || start + len > MAX_BLOCKS) {
                printf("Error: Blocks out of range!\n");
                continue;
            }

            // Check if blocks are free
            int isFree = 1;
            for (int i = start; i < start + len; i++) {
                if (memory[i] == 1) {
                    isFree = 0;
                    break;
                }
            }

            if (isFree) {
                for (int i = start; i < start + len; i++) {
                    memory[i] = 1;
                }
                strcpy(files[fileCount].name, fileName);
                files[fileCount].startBlock = start;
                files[fileCount].length = len;
                fileCount++;
                printf("File allocated successfully.\n");
            } else {
                printf("Error: Blocks already occupied!\n");
            }
        } else if (choice == 2) {
            printf("\n%-10s %-15s %-10s\n", "File", "Start Block", "Length");
            for (int i = 0; i < fileCount; i++) {
                printf("%-10s %-15d %-10d\n", files[i].name, files[i].startBlock, files[i].length);
            }
        } else if (choice != 3) {
            printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}
