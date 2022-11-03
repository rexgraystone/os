# Operating Systems

This repository contains all the C programs that I have executed for my Operating Systems Course in my 3rd Year of Computer Science Undergrad program at Dayananda Sagar University, Bengaluru, India in Q4 2022.

## List of Programs

| Serial No. | C File Name | Description |
| :---: | :--- | :--- |
| 1  | 1_ChildProcess.c  | Write a C program to create a new process that executes a new program using the following system calls: fork(), execlp() & wait(). |
| 2  | 2_PID.c  | Write a C program to display PID and PPID using system calls getpid () & getppid (). |
| 3  | 3_Files.c  | Write a C program using I/O system calls open(), read() & write() to copy contents of one file to another file. |
| 4  | 4_MultiThread.c  | Write a C program to implement multithreaded program using pthreads. |
| 5  | 5_RoundRobin.c  | Write C program to simulate the Round Robin CPU scheduling algorithms. |
| 6  | 6_ProdCons.c  | Write a C program to simulate producer-consumer problem using semaphores. |

## Miscellaneous Programs

## How to Run

1. Clone the repository using the following command:

``` bash
    gh repo clone rexgraystone/os
```

1. Change the directory to the cloned repository:

``` bash
    cd os
```
1. Compile the C program using the following command: 

``` bash
    gcc <C File Name> -o <Output File Name>
```

1. Run the program using the following command:

``` bash
    ./<Output File Name>
```
### Note

The programs are written in C and compiled using GCC compiler on macOS Ventura 13.0.
These programs will work on any Linux distribution and macOS. However, the programs may not work on Windows.
