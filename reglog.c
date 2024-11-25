#include <stdio.h>
#include <stdlib.h>
#include "reglog.h"
#include "ADT_Mesin_Karakter.h"
#include "ADT_Mesin_Kata.h"
#include "ADT_Kustom.h"

int session_active = 0; // Menandakan apakah sesi telah dimulai
int jumlahUsers = 0, i;
Word logged_in_user = { "", 0 }; // Menyimpan users[i].name yang sedang login

// Fungsi untuk membaca data dari file
void read_file(const char *file_name) {
    startFileKata(file_name); // Memulai pembacaan file

    if (EndWord || !isKataInt(currentWord)) {
        printf("Error: Format file salah.\n");
        return;
    }

    // Membaca jumlah barang
    int jumlahBarang = kataToInt(currentWord);
    ADVFileKata();

    // Membaca data barang
    for (int i = 0; i < jumlahBarang; i++) {
        if (EndWord || !isKataInt(currentWord)) break;

        items[i].price = kataToInt(currentWord);
        ADVFileKata();
        if (!EndWord) {
            wordToString(currentWord, items[i].name);
            ADVFileKata();
        }
    }

    // Membaca jumlah user
    if (!EndWord && isKataInt(currentWord)) {
        jumlahUsers = kataToInt(currentWord);
        ADVFileKata();
    }

    // Membaca data user
    for (int i = 0; i < jumlahUsers; i++) {
        if (EndWord) break;

        // Membaca saldo
        if (isKataInt(currentWord)) {
            users[i].money = kataToInt(currentWord);
            ADVFileKata();
        }

        // Membaca nama user
        if (!EndWord) {
            wordToString(currentWord, users[i].name);
            ADVFileKata();
        }

        // Membaca password
        if (!EndWord) {
            wordToString(currentWord, users[i].password);
            ADVFileKata();
        }
    }
}

// // Fungsi untuk menulis data user ke file
// void write_user_to_file(User users[], int jumlahUsers, const char *file_name) {
//     read_file(TXT_FILE);
//     FILE *file = fopen(TXT_FILE, "w");
//     if (file == NULL) {
//         printf("Error: Tidak dapat membuka file %s untuk menulis data.\n", file_name);
//         return;
//     }
// 
//     // Menulis jumlah pengguna
//     fprintf(file, "%d\n", jumlahUsers);
// 
//     // Menulis data pengguna ke file
//     for (int i = 0; i < jumlahUsers; i++) {
//         fprintf(file, "%d %s %s\n", users[i].money, users[i].name, users[i].password);
//     }
// 
//     fclose(file); // Menutup file
// }

// Fungsi untuk memeriksa apakah username sudah ada
int is_username_exists(const User users[], int jumlahUsers, const Word *username) {
    for (int i = 0; i < jumlahUsers; i++) {
        if (compareKata(*username, users[i].name)) {
            return 1; // Username ditemukan
        }
    }
    return 0; // Username tidak ditemukan
}

// Fungsi REGISTER
void register_user() {
    if (!session_active) {
        printf("Error: Anda harus memulai sesi terlebih dahulu dengan START.\n");
        return;
    }

    if (jumlahUsers >= MAX_USERS) {
        printf("Error: Jumlah pengguna maksimal telah tercapai.\n");
        return;
    }

    Word username, password;
    char kataSkrng[MAX_LEN];
    printf("Username: ");
    startKata();
    // wordToString(currentWord, kataSkrng);

    // printf("%s", kataSkrng);
    // copyKata();  // Mengambil username
    username = currentWord;
    // wordToString(username, kataSkrng);

    printf("Password: ");
    startKata();
    password = currentWord;
    // copyKata(currentWord, &password);  // Mengambil password

    wordToString(username, kataSkrng);

    if (is_username_exists(users, jumlahUsers, &username)) {
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", kataSkrng);
        return;
    }

    // Menyimpan username dan password ke dalam users
    copyString(&username, &users[jumlahUsers].name);
    copyString(&password, &users[jumlahUsers].password);
    users[jumlahUsers].money = 0; // Nilai default saldo
    jumlahUsers++;

    // write_user_to_file(users, jumlahUsers, TXT_FILE);
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", kataSkrng);
}

// Fungsi LOGIN
void login_user() {
    if (!session_active) {
        printf("Error: Anda harus memulai sesi terlebih dahulu dengan START.\n");
        return;
    }

    if (logged_in_user.Length > 0) {  // Mengecek apakah pengguna sudah login
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", logged_in_user.TabWord);
        return;
    }

    Word input_username, input_password;
    char logged_in_user[MAX_LEN];
    printf("Username: ");
    startKata();  // Membaca username
    copyKata(&currentWord, &input_username);

    printf("Password: ");
    startKata();  // Membaca password
    copyKata(&currentWord, &input_password);

    if (is_username_exists(users, jumlahUsers, &input_username)) {
        printf("Username atau password salah.\n");
        return;
    }
    else {  // Login berhasil
        wordToString(input_username, logged_in_user); // Menyimpan username yang login
        printf("Anda telah login ke PURRMART sebagai %s.\n", logged_in_user);
    }
}

// Fungsi untuk LOGOUT
void logout_user() {
    if (logged_in_user.Length == 0) {  // Menggunakan logged_in_user.Length untuk mengecek login status
        printf("Anda belum login.\n");
    } else {
        printf("Anda telah logout dari PURRMART.\n");
        logged_in_user.Length = 0; // Reset users[i].name yang login
        logged_in_user.TabWord[0] = '\0'; // Clear logged_in_user
    }
}
