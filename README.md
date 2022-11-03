# Operating Systems

This repository contains all the C programs that I have executed for my Operating Systems Course in my 3rd Year of Computer Science Undergrad program at Dayananda Sagar University, Bengaluru, India in Q4 2022.

## List of Programs

| Serial No. | C File Name | Description |
| :---: | :--- | :--- |
| 1  | 1_ChildProcess.c  | A C program to create a new process that executes a new program using the following system calls: fork(), execlp() & wait(). |
| 2  | 2_PID.c  | A C program to display PID and PPID using system calls getpid () & getppid (). |
| 3  | 3_Files.c  | A C program using I/O system calls open(), read() & write() to copy contents of one file to another file. |
| 4  | 4_MultiThread.c  | A C program to implement multithreaded program using pthreads. |
| 5  | 5_RoundRobin.c  | A C program to simulate the Round Robin CPU scheduling algorithms. |
| 6  | 6_ProdCons.c  | A C program to simulate producer-consumer problem using semaphores. |

## Miscellaneous Programs

| Serial No. | C File Name | Description |
| :---: | :--- | :--- |
| 1  | M1_LSearch.c  | A C program to search for a key element in an array using linear search algorithm. |
| 2  | M2_BSearch.c  | A C program to implement Binary Search using Recursion. |
| 3  | M3_Palindrome.c  | A C program to find whether a given string is a palindrome or not. |

## How to Run

1. Clone the repository using the following command:

    ``` bash
        gh repo clone rexgraystone/os
    ```

    or

    ``` bash
        git clone https://github.com/rexgraystone/daa.git
    ```

2. Change the directory to the cloned repository:

    ``` bash
        cd os
    ```

3. Compile the C program using the following command:

    ``` bash
        gcc <C File Name> -o <Output File Name>
    ```

4. Run the program using the following command:

    ``` bash
        ./<Output File Name>
    ```

### Note

The programs are written in C and compiled using GCC compiler on macOS Ventura 13.0.
These programs will work on any Linux distribution and macOS. However, the programs may not work on Windows.
