#include "functions.h"

// Global variables: The scope allows the data comunicatin between process
int counterFlag, interruptFlag, parentPid;

void interruptSignalController(int value) {
    interruptFlag ++;
    if (interruptFlag == 2) {
        exit(0);
    }
    if (getpid() != parentPid) {
        printf("Soy el hijo con pid: %d, y estoy vivo aún. No me mates papá\n", getpid());
    }
}

void counterSignalController(int value) {

    char *args[3];
    char* path = "contador";
    char counter[5];
    sprintf(counter, "%d", counterFlag);

    args[0] = path;
    args[1] = counter;
    args[2] = NULL;

    int pid = fork();
    if (pid == 0) {
        execv(args[0],args);
    }
    else {
        counterFlag++;
    }
}

void killSignalController(int value) {
    printf("Soy el hijo con pid: %d y mi papá me quiere matar\n", getpid());
    exit(1);
}

void forkSignalController(int value) {
    fork();
}

char convertSignal(int number) {

    return (char)(50 + number);
}

void init(int children, int mflag) {


    int x = 0;
    int y = 0;
    parentPid = getpid();
    int* pids = (int*)malloc(children * sizeof(int));

    signal(SIGINT, interruptSignalController);
    signal(SIGUSR1, counterSignalController);
    signal(SIGUSR2, forkSignalController);
    signal(SIGTERM, killSignalController);

    for (int i = 0; i < children; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            counterFlag = 0;
            break;
        }
    }

    if (getpid() == parentPid) {
        if (mflag) {
            printf("Mostrando la información por pantalla:\n");
            for (int i = 0; i < children; i++) {
                printf("Numero %d, pid: %d\n", i+1, pids[i]);
            }
        }

        char z;
        while(1) {
            printf(">> Ingresar núumero de hijo y señal a enviar (X - Y):\n");
            printf(">> ");
            scanf("%d - %d", &x, &y);
            printf(">> La señal %d será enviada al hijo %d de pid %d,\n", y, x, pids[x-1]);

            z = convertSignal(y);

            switch (z) {
                case 'A':
                    kill(pids[x-1], SIGTERM);
                    sleep(1);
                    break;
                case 'B':
                    kill(pids[x-1], SIGUSR1);
                    sleep(1);
                    break;
                case 'C':
                    kill(pids[x-1], SIGUSR2);
                    sleep(1);
                    break;
            }
        }
    }
    else {
        while (1) {
            /* children will be waiting for a signal until the parent dies*/
        }
    }

    free(pids);
}
