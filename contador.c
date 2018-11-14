#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

// Procedure: main
// Description: Signal's controller. It's the response
//              when the SIGINT signal was actived.
//              This procedure prints in the command
//              line a message if this signal has not
//              been recieved before by the actual process.
//
// Input: An integer and a pointer to strings. The
//        integer represents the amount of arguments
//        at the moment of the execution of the code.
//        The pointer to strings represents the commands
//        written to execute the code.
// Output: An integer (status code).
int main(int argc, char* argv[]) {
    /*
    argv[1] shoud be the counter
    if argv[1] = "1" then argv[1] - 48 = 1
    so argv[1] - 47 equals counter + 1
    */

    int contador = argv[1][0] - 47;
    printf(">> pid: %d, y he recibido esta llamada %d veces.\n", getppid(), contador);
    return 0;
}
