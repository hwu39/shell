CMSC 421 Spring 2018
Homework 2 Part 2
Author: Hongkun Wu

Program Description:
The shell program I have is able to run built-in commands. exit works with 0 or 1 arguments to exit the shell. If no argument is given, exit with status 0. If commands are invalid, display error. Both chdir and cd have the same functionalities. If the path is given, chdir or cd will redirect to that path. This can be checked with the command pwd. If the path is invalid, it will show the error message. If a third (or fourth, etc.) command exits, chdir or cd will simply ignore everything after the path. The echo command does parse the ASCII string. The output is right but there is some extra stuff compared to the sample output shown in the homework description. And, the echo command does the echo functionality if only a simple string of words is entered.
