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
    retval = fscanf(pita, "%c", &currentChar);
    if(currentChar == '\n' || currentChar == ';'){
        EOP = true;
    }
}

void startFile(char *file_name) {
    if (file_name == NULL){
        pita = stdin;
    } else {
        pita = fopen(file_name, "r");
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
    return (currentChar == MARK);
}