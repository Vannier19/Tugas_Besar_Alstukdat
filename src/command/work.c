#include <stdio.h>
#include "work.h"

void work(int *saldo) {
    printf("Daftar pekerjaan:\n");
    printf("1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");
    printf("Masukkan pekerjaan yang dipilih (1-5): ");
    startKata();
    int pilihan = 0;
    if (isKataInt(currentWord)) {
        pilihan = kataToInt(currentWord);
    } else {
        printf("Input tidak valid. Harap masukkan angka 1-5.\n");
        return;
    }

    int durasi = 0;
    int pendapatan = 0;
    
    if (pilihan == 1) {
        durasi = 14;
        pendapatan = 100;
        printf("Anda sedang bekerja sebagai Evil Lab Assistant... harap tunggu.\n");
    } else if (pilihan == 2) {
        durasi = 21;
        pendapatan = 4200;
        printf("Anda sedang bekerja sebagai OWCA Hiring Manager... harap tunggu.\n");
    } else if (pilihan == 3) {
        durasi = 30;
        pendapatan = 7000;
        printf("Anda sedang bekerja sebagai Cikapundunginator Caretaker... harap tunggu.\n");
    } else if (pilihan == 4) {
        durasi = 22;
        pendapatan = 10000;
        printf("Anda sedang bekerja sebagai Mewing Specialist... harap tunggu.\n");
    } else if (pilihan == 5) {
        durasi = 15;
        pendapatan = 997;
        printf("Anda sedang bekerja sebagai Inator Connoisseur... harap tunggu.\n");
    } else if (pilihan == 9090) {
        durasi = 5;
        pendapatan = 99999999;
        printf("Kode pekerjaan rahasia mata-mata telah dikonfirmasi... silakan tunggu sebentar, Tuan.\n");
    } else {
        printf("Pekerjaan tidak valid. Silakan pilih dari daftar pekerjaan.\n");
        return;
    }
    clock_t start_time = clock();
   while ((clock() - start_time) < durasi * CLOCKS_PER_SEC) {}
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", pendapatan);
    *saldo += pendapatan; // Menambahkan pendapatan ke saldo pengguna
}

// int main() {
//     int saldo = 0;
//     char lanjut = 'y';
//     while (lanjut == 'y' || lanjut == 'Y') {
//         work(&saldo);
//         printf("Saldo Anda saat ini: %d rupiah\n", saldo);
//         printf("Apakah Anda ingin bekerja lagi? (y/n): ");
//         scanf(" %c", &lanjut);
//     }
//     printf("Terima kasih telah bekerja. Saldo akhir Anda: %d rupiah\n", saldo);
//     return 0;
// }