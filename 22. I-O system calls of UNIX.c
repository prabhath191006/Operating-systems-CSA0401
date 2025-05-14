#include <fcntl.h>       // open(), O_CREAT, etc.
#include <unistd.h>      // read(), write(), close(), lseek()
#include <sys/stat.h>    // stat()
#include <stdio.h>
#include <string.h>

int main() {
    int fd;
    char buffer[50];
    struct stat fileStat;

    // Open or create file
    fd = open("example.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("Open failed");
        return 1;
    }

    const char *text = "Hello File System";         // 17 characters
    size_t len = strlen(text);                      // len = 17
    write(fd, text, len);                           // write 17 bytes

    lseek(fd, 0, SEEK_SET);                         // move to beginning
    read(fd, buffer, len);                          // read 17 bytes
    buffer[len] = '\0';                             // null-terminate

    printf("Content: %s\n", buffer);

    if (stat("example.txt", &fileStat) == 0) {
        printf("Size: %ld\n", fileStat.st_size);    // should be 17
        printf("Inode: %ld\n", fileStat.st_ino);
    } else {
        perror("stat failed");
    }

    close(fd);
    return 0;
}
