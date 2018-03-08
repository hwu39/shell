#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
pid_t pid;
	printf("Welcome to custom shell!!! \nType your commands at the prompt. \nEnter exit to exit!\n");
	while (1) {
	/*fork a child process*/
	//pid = fork();
	//define user argument, tokenized array of commands, and temp string
	char arg[256], *token[256],*temp;
	printf(">>> ");
	//check if user has entered nothing	
	if (gets(arg) != NULL) {
	/*fork a child process*/	
	pid = fork();	
	//tokenize user argument
	temp = strtok(arg," "); 
	int counter = 0;	
	while (temp != NULL) {	
		//store commands in array token	
		token[counter] = temp;
		counter++;
		temp = strtok(NULL, " ");
	}
	}	
	if (pid < 0) { /* error occurred*/
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0) { /* child process */
		//execute commands user has entered
		if (execvp(token[0],token) == -1) {
			//invalid command returns error
			perror("exec failed");
			return 1;
		}
	}
	//if user enters exit, exit program
	else if(strcmp(token[0], "exit") == 0) {
		break;
	} 
	else { /*parent process*/
		/*parent will wait for the child to complete*/
		wait(token);
	//	printf("Child Complete\n");
	}
	}
	return 0;

}
