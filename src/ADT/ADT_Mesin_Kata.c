#include <stdio.h>
#include "ADT_Mesin_Kata.h"

boolean EndWord;
Word currentWord;
int currSentenceWordCount;

void ignoreBlanks() {
    while ((currentChar == BLANK || currentChar == '\n') && !isEOP()) {
        ADV();
    }
}

void startKata() {
    start();
    ignoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        copyKata();
    }
    ignoreBlanks();
}

void ADVKata() {
    ignoreBlanks();

    if (isEOP() || currentChar == MARK) {
        EndWord = true;
    }
    else {
        copyKata();
        EndWord = false;
    }
    // ignoreBlanks();
}

void copyKata() {
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && !isEOP()) {
        if (currentWord.Length < NMax) { 
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        // else {
        //     break;
        // }
            // break;
        // ADV();
    }
}

void startFileKata(char* file_name) {
    startFile(file_name);
    ignoreBlanks();

    if (isEOP() || currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        copyKata();
        // ignoreBlanks();
        // if (currentChar == MARK) {
        //     EndWord = true;
        // }            
        // else {
        //     EndWord = false;
        //     copyKata();
        // }
    }
        // ignoreBlanks();
        // if (currentChar == MARK) {
        //     EndWord = true;
        // }            
        // else {
        //     EndWord = false;
        //     copyKata();
        // }
    // }
}

void ADVFileKata() {
    // resetCurrentKata();
    ignoreBlanks();
    // EndWord = false;

    if (isEOP() || currentChar == MARK) {
        EndWord = true;
    }
    else {
        copyKata();
        EndWord = false;
        // copySentence();
    }
}

void copySentence() {
    currentWord.Length = 0;
    currSentenceWordCount = 0;
    while (currentChar != MARK && currentChar != '\n'  && !isEOP()) {
        if (currentWord.Length < NMax) { 
            if (currentChar == BLANK) {
                currSentenceWordCount++;
            }
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else {
            break;
        }
            // break;
    }
}

void startLine() {
    // resetCurrentKata();
    start();

    if (currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        copySentence();
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