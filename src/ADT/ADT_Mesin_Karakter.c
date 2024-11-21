#include <stdio.h>
#include <stdlib.h>
#include "ADT_Mesin_Karakter.h"

char currentChar;
boolean EOP;
static FILE *pita = NULL;
static int retval;


void resetPita() {
    if (pita != NULL) {
        rewind(pita);
    }
}

void startFile(char* file_name, boolean *success) {
    // KAMUS LOKAL
    static char path[100] = "../src/";
    int i=0, len = 7;

    resetPita();

    // ALGORITMA
    // Nyalin nama filenya ke path buat dicari
    while (*file_name != '\0') {
        path[i+len] = *file_name;
        file_name++;
        i++;
    } 
    path[i+len] = '\0';

    pita = fopen(path, "r");
    if (pita != NULL) {
        *success = true;
        ADV();
    } else {
        *success = false;
    }
}

void start() {
    resetPita();

    pita = stdin;
    ADV();
}

void ADV() {
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
    return currentChar;
}

boolean isEOP() {
    return (currentChar == MARK);
}