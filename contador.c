#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

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
