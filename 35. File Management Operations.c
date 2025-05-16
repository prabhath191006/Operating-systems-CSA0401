#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char fileName[] = "example.txt";
    char buffer[256];

    // 1. Write to file (creates or overwrites)
    file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Hello, File Management!\n");
    fclose(file);
    printf("Data written to file.\n");

    // 2. Append to file
    file = fopen(fileName, "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "This line is appended.\n");
    fclose(file);
    printf("Data appended to file.\n");

    // 3. Read from file
    file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    printf("Reading file contents:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);

    // 4. Delete the file
    if (remove(fileName) == 0) {
        printf("File deleted successfully.\n");
    } else {
        perror("Error deleting the file");
    }

    return 0;
}
