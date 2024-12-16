#include <stdio.h>
#include <stdbool.h>
#include "ADT_Mesin_Kata.h"
#include "ADT_Kustom.h"
#define MAX_LEN 100
#define MAX_ITEMS 100


bool LOAD_Barang(char *filename, Barang barang[], int *jumlahBarang) {
    startFileKata(filename);
    //printf("Membaca data barang dari file %s...\n", filename);
    if (EndWord) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return false;
    }
    
    *jumlahBarang = kataToInt(currentWord);
    printf("Jumlah barang: %d\n", *jumlahBarang);
    
    for (int i = 0; i < *jumlahBarang; i++) {
        // Baca harga
        ADVFileKata();
        if (EndWord) {
            printf("Format file salah. PURRMART gagal dijalankan.\n");
            return false;
        }
        barang[i].price = kataToInt(currentWord);
        //printf("Harga barang: %d\n", barang[i].price);
        
        ADVFileKata();
        if (EndWord && i != *jumlahBarang - 1) {
            printf("Format file salah. PURRMART gagal dijalankan.\n");
            return false;
        }
        wordToString(currentWord, barang[i].name);
        //printf("Nama barang: %s\n", barang[i].name);
    }

    printf("Data barang berhasil dibaca. PURRMART berhasil dijalankan.\n");
    return true;
}

bool LOAD_User(char *filename, User users[], int *jumlahUser) {
    // Pastikan pointer file sudah berada di bagian data user
    if (!EndWord) {
        ADVKata(); // Pindahkan pointer ke kata berikutnya
    }

    if (EndWord) {
        printf("Data user tidak ditemukan.\n");
        return false;
    }

    // Membaca jumlah user
    *jumlahUser = kataToInt(currentWord); 
    printf("Jumlah user: %d\n", *jumlahUser);

    // Loop untuk membaca data setiap user
    for (int i = 0; i < *jumlahUser; i++) {
        // Membaca uang
        ADVKata();
        if (EndWord) {
            printf("Format file user salah: uang user ke-%d tidak ditemukan.\n", i + 1);
            return false;
        }
        users[i].money = kataToInt(currentWord);
        // printf("uang: %d\n", users[i].money);

        // Membaca nama user
        ADVKata();
        if (EndWord) {
            printf("Format file user salah: nama user ke-%d tidak ditemukan.\n", i + 1);
            return false;
        }
        wordToString(currentWord, users[i].name);
        // printf("uang: %s\n", users[i].name);

        // Membaca password user
        ADVFileKata();
        if (EndWord && i != *jumlahUser - 1) {
            printf("Format file user salah: password user ke-%d tidak ditemukan.\n", i + 1);
            return false;
        }
        wordToString(currentWord, users[i].password);
        // printf("password: %s\n", users[i].password);
    }

    printf("Data user berhasil dibaca.\n");
    return true;
}


// int main() {
//     Barang barang[MAX_ITEMS];
//     User users[MAX_ITEMS];
//     int jumlahBarang, jumlahUser;

//     // Load data barang dan user
//     if (LOAD_Barang("default.txt", barang, &jumlahBarang)) {
//         printf("\nDaftar Barang (%d item):\n", jumlahBarang);
//         for (int i = 0; i < jumlahBarang; i++) {
//             printf("%d. %s (Harga: %d)\n", i+1, barang[i].name, barang[i].price);
//         }
//         printf("\n");
        
//         if (LOAD_User("default.txt", users, &jumlahUser)) {
//             printf("\nDaftar User (%d user):\n", jumlahUser);
//             for (int i = 0; i < jumlahUser; i++) {
//                 printf("%d. %s (Money: %d, Password: %s)\n", 
//                        i+1, users[i].name, users[i].money, users[i].password);
//             }
//         }
//     }

//     return 0;
// }