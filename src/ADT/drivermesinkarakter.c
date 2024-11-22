#include <stdio.h>
#include "ADT_Mesin_Karakter.h"

int main() {
    // start();

    // while(!isEOP()) {
    //     printf("%c", currentChar);
    //     ADV();
    // }


    char fileName[100];

    printf("Masukkan nama file: ");
    scanf("%s", fileName);

    startFile(fileName);

    if (!isEOP()) {
        printf("Isi file:\n");
        while (!isEOP()) {
            printf("%c", getCC());
            ADVFile();   
        }
        printf("\n");
    } else {
        printf("Gagal membaca file atau file kosong.\n");
    }

    return 0;
}