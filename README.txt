CMSC 421 Spring 2018
Homework 1 Part 2
Author: Hongkun Wu

Program Description:
This program is a simple shell program that keeps reading in user command line arguments. The program will truncate the each argument and pass the commands to exec system call. Then, the program executes all the commands entered by the user. First, the program displays a prompt to ask for user input, and gets() is used to read in each command line argument. If user enters an empty string, nothing will execute (for safety). If invalid command is entered, execvp() will return -1. and error message is displayed. Shell program then detects whether the input is "exit". If exit is entered, the program is terminated immediately. When forking is complete, shell program stops forking and waits. When commands are executed successfully, return 0.
