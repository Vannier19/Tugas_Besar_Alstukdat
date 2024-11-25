#include <stdio.h>
#include "tebak_angka.h"

int generate_random_number() {
    time_t t;
    t = time(NULL);
    return (int)((t % 100) + 1);
}

void tebak_angka_game(int *saldo) {
    int target = generate_random_number();
    int tebakan = 0;
    int kesempatan = 10;
    int biaya_main = 200;
    int hadiah = 0;

    if (*saldo < biaya_main) {
        printf("Uang Anda tidak cukup untuk bermain (diperlukan %d rupiah).\n", biaya_main);
        return;
    }

    *saldo -= biaya_main;

    printf("Selamat datang di Tebak Angka!\n");
    printf("Anda memiliki %d kesempatan untuk menebak angka antara 1 - 100.\n", kesempatan);
    printf("Biaya main: %d rupiah telah dipotong dari akun Anda.\n", biaya_main);

    for (int i = 0; i < kesempatan; i++) {
        printf("Tebak angka (1-100): ");
        startKata(); 

        if (isKataInt(currentWord)) {
            tebakan = kataToInt(currentWord); 
        } else {
            printf("Input tidak valid. Harap masukkan angka antara 1-100.\n");
            i--; 
            continue;
        }

        if (tebakan < target) {
            printf("Tebakanmu lebih kecil!\n");
        } else if (tebakan > target) {
            printf("Tebakanmu lebih besar!\n");
        } else {
            hadiah = 500 - (i * 20);
            printf("Tebakanmu benar! +%d rupiah telah ditambahkan ke akun Anda.\n", hadiah);
            *saldo += hadiah;
            printf("ini saldo kamu %d",*saldo);
            return;
        }

        if (i == kesempatan - 1) {
            printf("Kesempatan habis! Angka yang benar adalah %d.\n", target);
        }
    }
}