#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    int srcFd, destFd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;
    char srcPath[256], destPath[256];

    // Get source file path
    printf("Enter source file path: ");
    scanf("%s", srcPath);

    // Get destination file path, default to "output.txt"
    printf("Enter destination file path (default is output.txt): ");
    if (scanf("%s", destPath) == 0) {
        strcpy(destPath, "output.txt");  // Default to "output.txt"
    }

    // Open source file with read-only permission
    srcFd = open(srcPath, O_RDONLY);
    if (srcFd < 0) {
        perror("Error opening source file");
        return 1;
    }

    // Open/create destination file with write permissions
    destFd = open(destPath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destFd < 0) {
        perror("Error opening/creating destination file");
        close(srcFd);
        return 1;
    }

    // Read from source and write to destination
    while ((bytesRead = read(srcFd, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = write(destFd, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Write error");
            close(srcFd);
            close(destFd);
            return 1;
        }
    }

    if (bytesRead < 0) {
        perror("Read error");
    } else {
        printf("File copied successfully using system calls.\n");
    }

    // Close file descriptors
    close(srcFd);
    close(destFd);

    return 0;
}
