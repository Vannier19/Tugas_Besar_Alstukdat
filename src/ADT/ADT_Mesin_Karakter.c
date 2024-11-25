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
    if(fscanf(pita,"%c", &currentChar)== MARK){
        EOP = true;
    } 
}

void startFile(const char *file_name) {
    pita = fopen(file_name, "r");
    if (pita == NULL){
        printf("File %s tidak ditemukan atau tidak dapat dibuka.\n", file_name);
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
    return feof(pita);
}