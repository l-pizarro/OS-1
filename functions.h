#pragma once
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Procedure: interruptSignalController
// Description: Signal's controller. It's the response
//              when the SIGINT signal was actived.
//              This procedure prints in the command
//              line a message if this signal has not
//              been recieved before by the actual process.
//
// Input: An integer (the signal number).
// Output: None.
void interruptSignalController(int value);

// Procedure: counterSignalController
// Description: Signal's controller. It's the response
//              when the SIGUSR1 signal was actived.
//              This procedure use the fork function to
//              create a child. The child use the execv
//              function to change their code for another one
//              that add one to a counter given on the argv
//              arguments and prints the result in the command
//              line. Then the child dies.
//
// Input: An integer (the signal number).
// Output: None.
void counterSignalController(int value);

// Procedure: killSignalController
// Description: Signal's controller. It's the response
//              when the SIGTERM signal was actived.
//              This procedure prints in the command
//              line a message before the process die.
//
// Input: An integer (the signal number).
// Output: None.
void killSignalController(int value);

// Procedure: forkSignalController
// Description: Signal's controller. It's the response
//              when the SIGUSR2 signal was actived.
//              This procedure create a new process, child
//              of the process that recieves the signal.
//
// Input: An integer (the signal number).
// Output: None.
void forkSignalController(int value);

// Function: convertSignal
// Description: This functions return a certain character which
//              depends of the number given on the parameters, used
//              on a switch case sentense.
// Input: An integer (the signal that the user sends).
// Output: A character that represents the signal on the parameters.
char convertSignal(int number);

// Procedure: init
// Description: This procedure ask for user inputs to send
//              signals between the several process created in
//              the begining of the execution.
//
// Input: Two integer values, the number of childs to create and the
//        flag.
// Output: None.
void init(int children, int flag);
