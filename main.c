#include "functions.h"

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
int main(int argc, char **argv) {

    int mflag = 0;
    int hflag = 0;
    int c;
    opterr = 0;

    while ((c = getopt(argc, argv, "mh:")) != -1) {
        switch (c) {
            case 'm':
                mflag = 1;
                break;
            case 'h':
                sscanf(optarg, "%d", &hflag);
                break;
            case '?':
                if (optopt == 'h') {
                    fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
                }
                else if (isprint(optopt)) {
                    fprintf(stderr, "Opcion desconocida '-%c'.\n", optopt);
                }
                else {
                    fprintf(
                            stderr,
                            "Opción con caracter desconocido '\\x%x'.\n",
                            optopt
                        );
                }
                return 1;
            default:
                abort();
        }
    }

    init(hflag, mflag);
    return 0;
}
