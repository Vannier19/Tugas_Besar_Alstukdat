#include <stdio.h>
#include "ADT_Mesin_Kata.h"

boolean EndWord;
Word currentWord;


void resetCurrentKata() {
    currentWord.Length = 0;
}

void ignoreBlanks() {
    while (currentChar == BLANK) {
        ADV();
    }
}

void startKata() {
    resetCurrentKata();
    start();
    ignoreBlanks();

    if (currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        ADVKata();
    }
}

void ADVKata() {
    resetCurrentKata();
    ignoreBlanks();

    if (currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        copyKata();
        ignoreBlanks();
    }
}

void copyKata() {
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK) && (i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        i += 1;
        ADV();
    }
    currentWord.Length = i;

    // currentWord.Length = 0;
    // while (currentChar != BLANK && currentChar != MARK) {
    //     if (currentWord.Length < NMax) { // jika lebih akan terpotong
    //         currentWord.TabWord[currentWord.Length++] = currentChar;
    //         ADV();
    //     } else
    //         break;
    //         }
}

void startFileKata(char* path) {
    boolean success;

    resetCurrentKata();
    startFile(path, &success);

    if (success) {
        if (currentChar == MARK) {
            EndWord = true;
        }            
        else {
            EndWord = false;
            copyKataDenganBlanks();
        }
    }
}

void ADVFileKata() {
    resetCurrentKata();
    EndWord = false;

    if (currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        copyKataDenganBlanks();
    }
}

void copyKataDenganBlanks() {
        int i = 0;
    while ((currentChar != MARK) && (i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        i += 1;
        ADV();
    }
    currentWord.Length = i;

    // currentWord.Length = 0;
    // while (currentChar != MARK) {
    //     if (currentWord.Length < NMax) { // jika lebih akan terpotong
    //         currentWord.TabWord[currentWord.Length++] = currentChar;
    //         ADV();
    //     } else
    //         break;
    //         }
}

void startLine() {
    resetCurrentKata();
    START();

    if (currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        copyKataDenganBlanks();
    }
}

boolean isKataEqual(Word kata1, Word kata2) {
    int i;
    
    if (kata1.Length != kata2.Length) {
        return false;
    }
    else {
        for (i=0; i<kata1.Length; i++) {
            if (kata1.TabWord[i] != kata2.TabWord[i]) {
                return false;
            }
        } return true;
    }
}

boolean isKataInt(Word kata) {
    int i;

    for (i=0; i<kata.Length; i++) {
        if (!(kata.TabWord[i] >= '0' && kata.TabWord[i] <= '9')) {
            return false;
        }
    } return true;
}

void displayKata(Word kata, boolean newLine) {
    int i=0;

    for (i=0; i<kata.Length; i++) {
        printf("%c", kata.TabWord[i]);
    } 

    if (newLine) {
        printf("\n");
    }
}

int kataToInt(Word kata) {
    int i, result=0;

    for (i=0; i<kata.Length; i++) {
        result = result*10 + (kata.TabWord[i] - '0');
    } return result;
}