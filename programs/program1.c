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
    char *token = strtok(input, " "); // Splits the input string into tokens
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
        
        if (strcmp(args[0], "cd") == 0) { 
            if (strcmp(args[1], "-") == 0) {  // Command enables to switch to the last working directory
                chdir(getenv("OLDPWD"));  // Changes working directory to previous directory
            }
                else chdir(args[1]); // Changes working directory that is specified in args[1] e.g. cd Desktop changes directory to Desktop
            
        } else if (strcmp(args[0], "exit") == 0) { // Exits process
            exit(EXIT_SUCCESS);
            
        } else if (strcmp(args[0], "help") == 0) {
            printf("This is the help section.\n");
            printf("Available commands: ls, mkdir, uptime, cd \n");
            
        } else if (strcmp(args[0], "ls") == 0) { 

            // TASK 1.2. INTERMEDIATE: ls additional argument
            int i = 1;
            while (args[i] != NULL) {
                if (strcmp(args[i], "-l") == 0) { // Searches if there is -l
                    // If -l is there, args array is modified
                    args[0] = "ls";
                    args[1] = "-l";
                    args[2] = NULL;
                    execute_command(args);
                    
                }
                i++;  // If -l is not at index[i], i is incremented
            }

            execute_command(args); // If -l is not presented only ls is executed
            
        } else if (strcmp(args[0], "mkdir") == 0) {

            // TASK 1.2. INTERMEDIATE: mkdir additional argument                    
	    int i = 1;
            while (args[i] != NULL) {
                if (strcmp(args[i], "-p") == 0) {
                    
                    // If -p is present, args array is modified
                    args[0] = "mkdir";  
                    args[1] = "-p";
                    args[2] = args[i+1];
                    args[3] = NULL;
                    execute_command(args);
                    
                }
                i++;
            }                    
            // Executes if -p is not present 
            execute_command(args);


      }    else {
            
            // Execute different command
            execute_command(args);		
        }
    
}

int main(void) {
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



