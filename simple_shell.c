#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/wait.h>
#include "utils.h"

int read_line(char *buf);

int main()
{
  pid_t pid;
  printf("Welcome to custom shell!!! \nType your commands at the prompt. \nEnter exit to exit!\n");
  while (1) {
    //define user argument, tokenized array of commands, and temp string
    char *token = malloc(sizeof(char)),*temp;
    int size = read_line(token);
    
    //tokenize user argument
    temp = strtok(token," "); 
    int counter = 0;	
    char *arg[size];
    while (temp != NULL) {	
      //store commands in array token	
      arg[counter++] = temp;
      temp = strtok(NULL, " ");
    }

    //replace echo functionality
    if (strcmp(arg[0], "echo") == 0 || strcmp(arg[0], "/bin/echo") == 0){
	FILE *errf = NULL;	
	char *tmp;
	tmp = unescape(arg[1],errf);	  
	printf(tmp);
	//skip built-in commands
	continue;
    }
    /*fork a child process*/
      pid = fork();
    //check if user has entered anything
    if ( size > 0) {  
      if (pid < 0) { /* error occurred*/
	fprintf(stderr, "Fork Failed");
	return 1;
      } 
      else if (pid == 0) { /* child process */
	//execute commands user has entered
	if (execvp(arg[0],arg) == -1) {
	  //invalid command returns error
	  //perror("exec failed");
	  return 1;
	}
      }
      //if user enters exit, exit program
      else if (strcmp(arg[0], "exit") == 0) {
	if (arg[1] == NULL) {//single exit 
	  exit(EXIT_SUCCESS);
	  break;
	}
	else if (strcmp(arg[1], "0") == 0) {//exit with 0
	  exit(EXIT_SUCCESS);
	}
	else if (strcmp(arg[1], "1") == 0) {//exit with 1
	  exit(EXIT_FAILURE);
	}
	printf("Imcompatible command with exit\n");
      }
      else if(strcmp(arg[0], "chdir") == 0 || strcmp(arg[0], "cd") == 0 || strcmp(arg[0], "/bin/chdir") == 0 || strcmp(arg[0], "/bin/cd") == 0){
	//commands are ommited after the second one
	if (arg[2] != NULL) {
	  int i;
	  for (i = 2; i < size; i++) {
	    arg[i] = NULL;
	  }
	}
	
	if (arg[1] == NULL) {	
	  chdir("/home");
	}
	else {
	  chdir(arg[1]);
	}
      }
      else { /*parent process*/
	/*parent will wait for the child to complete*/
	pid = wait(NULL);
	//printf("Child Complete\n");
      }
    }
  }
  return 0; 
}

int read_line(char *buf)
{
  int i, j;
  i = 0;
  do {
    j = fgetc(stdin);
    if (j == '\n' || j == EOF) {
      return i;
    }
    else {
      buf[i] = j;
      i++;
    }
  } while(1);
  return i;

}
