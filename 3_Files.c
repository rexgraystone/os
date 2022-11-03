/*
3.  Write a C program using I/O system calls 
    open(), read() & write() to copy contents 
    of one file to another file
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    char buff;
    int fd, fd1;
    fd = open("one.txt", O_RDONLY);
    fd1 = open("two.txt", O_WRONLY|O_CREAT);
    while(read(fd, &buff, 1))
        write(fd1, &buff, 1);
    printf("The file has been copied successfully.\n");
    close(fd);
    close(fd1);
    return 0;
}