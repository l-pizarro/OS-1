#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

// Procedure: main
// Description: The main function of the code. Allows
//              the execution of the program.
//
// Input: An integer and a pointer to strings. The
//        integer represents the amount of arguments
//        at the moment of the execution of the code.
//        The pointer to strings represents the commands
//        written to execute the code.
// Output: An integer (status code).
int main(int argc, char* argv[]) {

    int contador = atoi(argv[1]);
    printf(">> pid: %d, y he recibido esta llamada %d veces.\n", getppid(), contador);
    return 0;
}
