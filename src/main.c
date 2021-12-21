#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/util.h"
//kreep compie filename.kr

int main(int argc, char** argv){
    if(argc <3){
        printf("Too less arguments");
        return 1;
    }

    if(strcmp(argv[1], "compile") == 0){
        char* source = read_ascii_file(argv[2]);
        printf("$s\n, source");
        free(source);
    }
    return 0;
}