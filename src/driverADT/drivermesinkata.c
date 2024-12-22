#include <stdio.h>
#include "../ADT/ADT_Mesin_Kata.h"

int main() {
    char fileName[100];
    boolean fromFile;

    printf("Pilih mode input (1: stdin, 2: file): ");
    int mode;
    scanf("%d", &mode);
    getchar();

    if (mode == 2) {
        fromFile = true;
        printf("Masukkan nama file: ");
        scanf("%s", fileName);
        startFileKata(fileName);
    } else {
        fromFile = false;
        printf("Masukkan teks (akhiri dengan ';'): ");
        startKata();
    }

    printf("Hasil pembacaan kata:\n");
    while (!EndWord) {
        displayKata(currentWord, true);
        if (fromFile) {
            ADVFileKata();
        } else {
            ADVKata();
        }
    }

    printf("Pembacaan selesai.\n");
    return 0;
}