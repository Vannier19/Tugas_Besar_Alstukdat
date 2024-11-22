#include <stdio.h>
#include <stdlib.h>
#include "ADT_Mesin_Karakter.h"

char currentChar;
boolean EOP;
static FILE *pita = NULL;
static int retval;

void start() {
    pita = stdin;
    ADV();
}

void ADV() {
    // retval = fscanf(pita, "%c", &currentChar);
    // if(currentChar == '\n' || currentChar == ';'){
    //     EOP = true;
    // }
    retval = fscanf(pita, "%c", &currentChar);
    if (currentChar == '\r'){
           retval = fscanf(pita, "%c", &currentChar);
    }
    EOP = feof(pita);
}

void startFile(char *file_name) {
    pita = fopen(file_name, "r");
    if (pita == NULL){
        // EOP = true;
        printf("File %s tidak ditemukan atau tidak dapat dibuka.\n", file_name);
        // currentChar = '\0';
        exit(1);
    }
    ADV();
}

void ADVFile() {
    if (pita == NULL) {
        EOP = true;
    }
    else {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = feof(pita);

        if (EOP) {
            fclose(pita);
        }
    }
}

char getCC() {
    return currentChar;
}

boolean isEOP() {
    return EOP;
}