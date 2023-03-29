# OS-Project

Members: Aldin Talić, Admir Nedžibović

Listing of files/directories in submission: Main folder "OS-Project" contains: README.md, task1.5.pdf and a subfolder called "programs". Within the "programs" subfolder, there are the programs: program1.c, program2.c, and program3.c. 

Sources used: geeksforgeeks.org, man7.org, section.io

Note: In all programs, the code is commented in detail 

*******************

program1.c  => Task 1.1. advanced, Task 1.2. basic, intermediate, Task 1.3. basic

This program covers Task 1.1 (advanced), Task 1.2 (basic, intermediate) and Task 1.3 (basic).The program is in an infinite loop, always asking the user for input. The prompt is in the machinename@username:~$ format (Task 1.1. advanced) and it changes depending on the machine and user. The commands cd, ls, mkdir, uptime are implemented (Task 1.2. basic), as well as two additional commands "help" and "exit". The cd, ls and mkdir commands are implemented in a way allowing them to have more options (Task 1.2. Intermediate). The program also includes the implementation of fork(), exec() and wait() (Task 1.3. basic). 

Instructions for compiling: 
- open terminal in "programs" directory. 
- to compile type gcc -Wall -o program1 program1.c 
- to run ./program1

*******************

program2.c  => Task 1.3. intermediate, Task 1.4. 

This program covers Task 1.3 (Intermediate) and Task 1.4. It is a simple program where the child process print its ID and the parent process prints its ID. A new process is created using the vfork() system call and the child lists all the contents of the Desktop directory through the execl() system call (Task 1.3. intermediate). As it is said in the code, the path to the Desktop will vary from machine to machine of course. The wait() system call is implemented so the parent always waits for the child to finish. Also, both the child and parent process will print its output in different colors (Task 1.4.). 

Instructions for compiling: 
- open terminal in "programs" directory. 
- to compile type gcc -Wall -o program2 program2.c 
- to run ./program2

*******************

program3.c => Task 1.3. additionally

This program covers Task 1.3 (Additionally). It simply implements a forkbomb. Basically, the program is in an infinite loop and it constantly creates new processes. Doing this, the machine can become overloaded and it will eventually crash. 

Instructions for compiling: 
- open terminal in "programs" directory. 
- to compile type gcc -Wall -o program3 program3.c 
- to run ./program3

*******************

task1.5.pdf contains the answers to the questions. 