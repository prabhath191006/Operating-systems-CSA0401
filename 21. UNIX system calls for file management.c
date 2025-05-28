#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100], readBuffer[100];
    ssize_t bytesRead, bytesWritten;

    // Create and write to file
    fd = open("myfile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("File creation failed");
        return 1;
    }

    printf("Enter text to write into the file: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        perror("Input error");
        close(fd);
        return 1;
    }

    bytesWritten = write(fd, buffer, strlen(buffer));
    if (bytesWritten < 0) {
        perror("File write failed");
        close(fd);
        return 1;
    }

    close(fd);

    // Open and read from file
    fd = open("myfile.txt", O_RDONLY);
    if (fd < 0) {
        perror("File open failed");
        return 1;
    }

    bytesRead = read(fd, readBuffer, sizeof(readBuffer) - 1);
    if (bytesRead < 0) {
        perror("File read failed");
        close(fd);
        return 1;
    }

    readBuffer[bytesRead] = '\0'; // Null-terminate the read string

    printf("\nContents of file:\n%s", readBuffer);
    close(fd);

    return 0;
}
