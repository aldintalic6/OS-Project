#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE 80

void parse_input(char *input, char **args) { // Splits the input string into separate words and stores them into the args array e.g. input = ls -l => args[0] = ls, args[1] = -l
    
    // Parse input into arguments
    int i = 0;
    char *token = strtok(input, " ");   // Splits the input string into tokens
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

void execute_command(char **args) {
    
    int pid = fork();  // Forks process
    if (pid == 0) { // Child process
    
        int execvariable = execvp(args[0], args);  // Executes command specified by args
        if (execvariable == -1) {
	        printf("Command not found: %s\n", args[0]); // If execvp returns -1, error occurred (command was not found)
            exit(EXIT_FAILURE); }            
        }
         else {
            // Parent process
            wait(NULL);  // Parent waits till child is finished
    }
}

void machinename_username() {  // TASK 1.1.
    
    // Function used to get the machinename and username

    char *username = getenv("USER"); // Returns the username
    char hostname[MAX_LINE];
    
    if (gethostname(hostname, MAX_LINE) != 0) {
            printf("Error getting hostname: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        } 
    printf("%s@%s:~$ ", hostname, username);  
    
}

void commands(char **args) {
			    
        // Built-in functions
        // strcmp() compares two strings, returns 0 if they are equal
        
        if (strcmp(args[0], "sl") == 0) {  // SL -  Needs to be installed with sudo apt install sl
	        args[1] = NULL;
	        execute_command(args);  

        } else if (strcmp(args[0], "exit") == 0) { //  EXIT - Exits process
            exit(EXIT_SUCCESS);
            
        } else if (strcmp(args[0], "help") == 0) {   // HELP
            printf("This is the help section.\n");
            printf("Available commands: exit, ls, mkdir, uptime, sl \n");
            
        } else if (strcmp(args[0], "ls") == 0) {  // LS

            // TASK 1.2. INTERMEDIATE: ls additional argument

		if (args[1] == NULL || strcmp(args[1], "-l") == 0) {
		// If only ls is inputted or ls -l 
		execute_command(args);
}

	   	else if (strcmp(args[1], "-l") != 0) { // If any other option is inputted

		   printf("Only -l option is available for ls\n");
		}
		
        } else if (strcmp(args[0], "mkdir") == 0) {     // MKDIR

            // TASK 1.2. INTERMEDIATE: mkdir additional argument    
                   
	       if (args[1] == NULL) {

		    printf("Use mkdir with -p\n");
		}
	 
               else if (strcmp(args[1], "-p") == 0) {
                    
                    // If -p is present, command is executed
                    execute_command(args);
                    
                }

		else if (strcmp(args[1], "-p") != 0) { // If -p is not present

		    printf("Only -p option is available for mkdir\n");		

		}          
	
        } else if (strcmp(args[0], "uptime") == 0) {  // UPTIME

            args[1] = NULL;
            execute_command(args);  

        } else if (strcmp(args[0], "clear") == 0) {   // CLEAR

            args[1] = NULL;
            execute_command(args);

      } else {
            
            // If user enters command that doesn't exist
            printf("Command not found\nType 'help' to see available commands\n");		
        }
    
}

int main() {
    char input[MAX_LINE]; 
    char *args[MAX_LINE/2 + 1]; 

    while (1) {   // Infinite loop that asks user for input
        
        machinename_username();

        fgets(input, MAX_LINE, stdin); // Used to read input from user 
        input[strlen(input)-1] = '\0'; // Last character in string needs to be '\0' 

        parse_input(input, args);   // Sends input to get parsed
                        	    	                                                                                   
	    commands(args); // Calls command

}

return 0;
}



