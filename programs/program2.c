#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#define MAX_LINE 80

int main() {

	int status, pid, checkexecl;
	char *purple_color = "\033[0;35m";
	char *red_color = "\033[1;31m";
	pid = vfork(); // Creating new process

	if (pid == 0) { // Child process
	
	printf(purple_color); // Setting the color of the shell when printing
	printf("Child process ID: %d ", (int) getpid()); // Getting the ID of the child process
	printf("\n");
	
	// Using execl to list the contents of the Desktop directory (the path varies from machine to machine)
	checkexecl = execl("/bin/ls", "/bin/ls", "/Users/aldintalic/Desktop", NULL); 
	if (checkexecl == -1) {

	printf("execl failed "); // If execl returns -1, it failed
	exit(EXIT_FAILURE);

	}
	}

	else if (pid > 0) {  // Parent process

	wait(&status); // Parent will wait until child is finished
	printf(red_color);
	printf("Parent process ID: %d ", (int) getpid());
	printf("\n");
	}

return 0;
}
