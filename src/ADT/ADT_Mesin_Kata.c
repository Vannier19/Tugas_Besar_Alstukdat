#include <stdio.h>
#include <stdlib.h>
#include "ADT_Mesin_Kata.h"

boolean EndWord;
Word currentWord;
int currSentenceWordCount;

void ignoreBlanks() {
    while ((currentChar == BLANK || currentChar == '\n' || currentChar == '\r') && !isEOP()) {
        ADV();
    }
}

void startKata() {
    start();
    ignoreBlanks();
    if (currentChar == EOF) {
        EndWord = true;
    }
    else if (currentChar == MARK || currentChar == '\n') {
        EndWord = true;
    }
    else {
        EndWord = false;
        copyKata();
    }
}

void ADVKata() {
    ignoreBlanks(); // Abaikan spasi dan karakter kosong sebelum membaca kata
    if (currentChar == MARK || isEOP()) { // Jika akhir file
        EndWord = true;
    } else {
        copyKata(); // Salin kata dari file ke currentWord
        EndWord = false;
    }
}

void copyKata() {
    currentWord.Length = 0; // Reset panjang kata

    // Loop selama bukan akhir file, bukan spasi, dan bukan newline
    while (!isEOP() && currentChar != BLANK && currentChar != '\n' && currentChar != MARK) {
        if (currentWord.Length < NMax) { // Pastikan panjang kata tidak melebihi batas
            currentWord.TabWord[currentWord.Length++] = currentChar;
        }
        ADV(); // Pindahkan ke karakter berikutnya
    }
    currentWord.TabWord[currentWord.Length] = '\0'; // Tambahkan terminator string
}



void copyFileKata() {
    currentWord.Length = 0;
    boolean isNumber = true;

    if (currentChar < '0' || currentChar > '9') {
        isNumber = false;
    }

    while (!isEOP() && currentChar != MARK && currentChar != '\n') {
        if (isNumber) {
            if (currentChar < '0' || currentChar > '9' || currentChar == BLANK) {
                break;
            }
        } else {
            if (currentChar == '\n') {
                break;
            }
        }

        if (currentWord.Length < NMax) {
            currentWord.TabWord[currentWord.Length++] = currentChar;
        }
        ADV();
    }
    currentWord.TabWord[currentWord.Length] = '\0';
}

void startFileKata(const char* file_name) {
    startFile(file_name);
    ignoreBlanks();

    if (isEOP() || currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        copyFileKata();
    }
}

// void ADVFileKata() {
//     // resetCurrentKata();
//     ignoreBlanks();
//     // EndWord = false;

//     if (isEOP() || currentChar == MARK) {
//         EndWord = true;
//     }
//     else {
//         copyKata();
//         // EndWord = false;
//         // copySentence();
//     }
// }

void ADVFileKata() {
    ignoreBlanks();
    if (currentChar == MARK || isEOP()) {
        EndWord = true;
    }
    else {
        copyFileKata();
    }
}

void copySentence() {
    currentWord.Length = 0;
    currSentenceWordCount = 0;
    while (currentChar != MARK && currentChar != '\n' && !isEOP()) {
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
    }
}

void startLine() {
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
    if (kata1.Length != kata2.Length) {
        return false;
    }
    
    for (int i = 0; i < kata1.Length; i++) {
        if (kata1.TabWord[i] != kata2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

boolean isKataInt(Word kata) {
    for (int i = 0; i < kata.Length; i++) {
        if (!(kata.TabWord[i] >= '0' && kata.TabWord[i] <= '9')) {
            return false;
        }
    }
    return true;
}

void displayKata(Word kata, boolean newLine) {
    for (int i = 0; i < kata.Length; i++) {
        printf("%c", kata.TabWord[i]);
    }
    if (newLine) {
        printf("\n");
    }
}

int kataToInt(Word kata) {
    int result = 0;
    for (int i = 0; i < kata.Length; i++) {
        result = result * 10 + (kata.TabWord[i] - '0');
    }
    return result;
}

int isEqualChar(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}

int compareKata(Word kata, const char *str) {
    int i;
    for (i = 0; i < kata.Length && str[i] != '\0'; i++) {
        if (kata.TabWord[i] != str[i]) {
            return 0;
        }
    }
    return (i == kata.Length && str[i] == '\0');
}

void wordToString(Word w, char *str) {
    for (int i = 0; i < w.Length; i++) {
        str[i] = w.TabWord[i];
    }
    str[w.Length] = '\0';
}