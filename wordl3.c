#include "wordl3.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *validWords[] = {"harum", "putih", "bunga", "apple", "mango", "peach", "lemon", "melon", "berry", "guava"};
char *targetWord;

// Fungsi untuk membandingkan dua buah string
int isEqualChar(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
            // i++;
        }
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
    // return true;
}

// Fungsi untuk memilih angka acak yang akan berperan sebagai indeks dari targetWord
int randomNumberGenerate() {
    return (rand() % 11); 
}

// Fungsi untuk mengecek apakah sebuah karakter ada di dalam sebuah string
int isCharInWord(char c, char *word) {
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] == c) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Fungsi untuk mencetak hasil pengecekan dari tebakan
void printFeedback(char *tebakan, char *targetWord) {
    for (int i = 0; i < 5; i++) {
        if (tebakan[i] == targetWord[i]) {
            printf("%c ", tebakan[i]); 
        } 
        else if (isCharInWord(tebakan[i], targetWord)) {
            printf("%c%% ", tebakan[i]);
        } 
        else {
            printf("%c* ", tebakan[i]);
        }
    }
    printf("\n");
}

void initializeHistory(char history[6][6]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            history[i][j] = '_'; // Inisialisasi dengan '_'
        }
    }
}

void printHistory(char history[6][6]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", history[i][j]); // Cetak karakter di history
        }
        printf("\n");
    }
}

// Proses utama permainan
void playGame(int *saldo) {
    // Memilih targetWord
    srand(time(NULL));
    int targetIdx = randomNumberGenerate();
    targetWord = validWords[targetIdx];

    int attempts = 7;
    int statusMenang = 0;
    int biayaWordl = 500;
    int hadiahWordl = 1500;

    if (*saldo < biayaWordl) {
        printf("Yah... sayang sekali saldo Anda tidak cukup untuk bermain WORDL3.\n");
        return;
    }

    // char results[MAX_ATTEMPTS][WORD_LENGTH + 1] = {{0}};
    // int currentAttempt = 0;
    *saldo -= biayaWordl;
    printf("WELCOME TO W0RDL3, YOU HAVE %d CHANCES TO ANSWER BEFORE YOU LOSE!\n\n", MAX_ATTEMPTS);
    char history[6][6];
    initializeHistory(history);
    
    int currentAttempt = 0;

    for (int i = 0; i<MAX_ATTEMPTS; i++) {
        printf("_ _ _ _ _\n");
    }

    // char history[6][6];
    // initializeHistory(history);
    while (attempts > 0 && !statusMenang) {
        // Input tebakan
        printf("\nMasukan kata tebakan Anda: ");
        startKata();

        // Ubah currentWord menjadi string
        char tebakan[6] = {'\0'};
        for (int i=0; i<currentWord.Length; i++) {
            tebakan[i] = currentWord.TabWord[i];
        }
        tebakan[currentWord.Length] = '\0'; // ini null-terminator sebuah string

        for (int i = 0; i < 5; i++) {
            history[currentAttempt][i] = tebakan[i];
        }
        currentAttempt++;

        // Cek tebakan bener atau engga
        if (isEqualChar(tebakan, targetWord) == true) {
            printf("Selamat Anda menang!!\n");
            printf("+1500 rupiah telah ditambahkan ke saldo akun Anda.\n");
            statusMenang = 1;
            *saldo += hadiahWordl;
            break;
        } else {
            printf("Hasil:\n");
            printFeedback(tebakan, targetWord);
            attempts--;
        }

        // Tambahkan debug di sini
        printf("statusMenang: %d, attempts: %d\n", statusMenang, attempts);
    }
    // Kesempatan sudah abis, jadi kalah
    if (!statusMenang) {
        printf("Boo! Anda kalah. Kata yang benar adalah: %s\n", targetWord);
    }
}
