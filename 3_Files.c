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
    fd1 = open("one.txt", O_RDONLY); // open the file one.txt in read only mode
    fd2 = open("two.txt", O_WRONLY|O_CREAT); // open the file two.txt in write only mode, if it doesn't exist, create it
    while(read(fd1, &buff, 1)) { // read the file one.txt
        write(fd2, &buff, 1); // write to the file two.txt
    }
    printf("The file has been copied successfully.\n"); // print the file has been copied successfully
    close(fd1); // close the file one.txt
    close(fd2); // close the file two.txt
    return 0; 
}