/*
    3.  Write a C program using I/O system calls 
        open(), read() & write() to copy contents 
        of one file to another file.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    char buff; // buff = buffer
    int fd1, fd2; // fd1 = file descriptor for one.txt, fd2 = file descriptor for two.txt
    fd1 = open("one.txt", O_RDONLY); 
    fd2 = open("two.txt", O_WRONLY|O_CREAT); 
    while(read(fd1, &buff, 1)) { 
        write(fd2, &buff, 1); 
    }
    printf("The file has been copied successfully.\n"); 
    close(fd1); 
    close(fd2); 
    return 0; 
}