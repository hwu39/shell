CMSC 421 Spring 2018
Homework 2 Part 2
Author: Hongkun Wu

Program Description:
The shell program I have is able to run built-in commands. exit works with 0 or 1 arguments to exit the shell. If no argument is given, exit with status 0. If commands are invalid, display error. Both chdir and cd have the same functionalities. If the path is given, chdir or cd will redirect to that path. This can be checked with the command pwd. If the path is invalid, it will show the error message. If a third (or fourth, etc.) command exits, chdir or cd will simply ignore everything after the path. The echo command should unescape the given string and print it out, followed by a newline on the user's standard output. My shell passes the string to the utils file, but it only works on certain strings. And, the strings are sometimes not parsed properly.
