#include <stdio.h>

void generateParam(int mode)
{
    char * path = "C:\\Users\\Alex\\Documents\\Travaux\\C\\HeXart\\HeXart\\arduino_Cardio\\param.h";

    FILE * file = fopen(path, "w+");

    fprintf(file, "#ifndef ARDUINO_CARDIO_PARAM_H\n"
                  "#define ARDUINO_CARDIO_PARAM_H\n"
                  "\n"
                  "#define MODE %d\n"
                  "#define CHOICE 1\n"
                  "\n"
                  "#endif", mode);

    printf("File has been generated with mode %d", mode);

    fclose(file);
}
