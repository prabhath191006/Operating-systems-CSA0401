#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char directory[MAX][30];
    int fileCount = 0;
    int choice;
    char filename[30];

    while (1) {
        printf("\n---- Single-Level Directory ----\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display Files\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter file name to create: ");
                scanf("%s", filename);
                // Check if file already exists
                int exists = 0;
                for (int i = 0; i < fileCount; i++) {
                    if (strcmp(directory[i], filename) == 0) {
                        exists = 1;
                        break;
                    }
                }
                if (exists) {
                    printf("File already exists.\n");
                } else {
                    strcpy(directory[fileCount], filename);
                    fileCount++;
                    printf("File created successfully.\n");
                }
                break;

            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", filename);
                int found = 0;
                for (int i = 0; i < fileCount; i++) {
                    if (strcmp(directory[i], filename) == 0) {
                        found = 1;
                        // Shift remaining files
                        for (int j = i; j < fileCount - 1; j++) {
                            strcpy(directory[j], directory[j + 1]);
                        }
                        fileCount--;
                        printf("File deleted successfully.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("File not found.\n");
                }
                break;

            case 3:
                printf("Enter file name to search: ");
                scanf("%s", filename);
                found = 0;
                for (int i = 0; i < fileCount; i++) {
                    if (strcmp(directory[i], filename) == 0) {
                        found = 1;
                        printf("File found at position %d.\n", i + 1);
                        break;
                    }
                }
                if (!found) {
                    printf("File not found.\n");
                }
                break;

            case 4:
                if (fileCount == 0) {
                    printf("Directory is empty.\n");
                } else {
                    printf("Files in directory:\n");
                    for (int i = 0; i < fileCount; i++) {
                        printf("%d. %s\n", i + 1, directory[i]);
                    }
                }
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
