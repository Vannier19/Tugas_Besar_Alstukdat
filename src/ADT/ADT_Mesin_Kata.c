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

void startKalimat() {
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
        copyFileKata();
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

int compareKata(Word kata, char *str) {
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

void copyString(char *destination, char *source) {
    int i = 0;
    // Menyalin setiap karakter hingga menemukan null terminator
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    // Menambahkan null terminator pada akhir string tujuan
    destination[i] = '\0';
}

int stringLength(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int compareStrings(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0; // Tidak sama
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0'); // Sama jika keduanya null-terminated
}

int stringToInt(char *str) {
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

boolean isNumString(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;  // Jika ada karakter yang bukan angka
        }
    }
    return true;
}

Word stringToWord(char *str) {
    Word kata;
    int i = 0;
    
    while (str[i] != '\0' && i < NMax - 1) {
        kata.TabWord[i] = str[i];
        i++;
    }
    kata.TabWord[i] = '\0';
    kata.Length = i;
    
    return kata;
}

void split4Kata(char *kalimat, char *kata[]) {
    int i = 0, j = 0, kataKe = 0;

    // Inisialisasi semua elemen kata dengan string kosong
    for (int k = 0; k < 4; k++) {
        kata[k][0] = '\0';
    }

    while (kalimat[i] != '\0') {
        if (kalimat[i] != ' ') {
            kata[kataKe][j++] = kalimat[i];
        } else {
            kata[kataKe][j] = '\0'; // Akhiri kata
            kataKe++;
            j = 0;

            if (kataKe == 4) break; // Maksimal 4 kata
        }
        i++;
    }
    kata[kataKe][j] = '\0'; // Akhiri kata terakhir
}


int comparePanjangString(char *str1, char *str2) {
    int i = 0;
    
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}