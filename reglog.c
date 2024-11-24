#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reglog.h"
#include "ADT_Mesin_Karakter.h"
#include "ADT_Mesin_Kata.h" // Include Mesin Karakter dan Mesin Kata

int session_active = 0; // Menandakan apakah sesi telah dimulai
Word logged_in_user = { "", 0 }; // Menyimpan username yang sedang login

// Fungsi untuk menulis data ke file
void write_user_to_file(const Word *username, const Word *password) {
    FILE *file = fopen(TXT_FILE, "a");
    if (!file) {
        printf("Error: Tidak dapat membuka file %s untuk menulis data.\n", TXT_FILE);
        return;
    }
    fprintf(file, "%s %s\n", username->TabWord, password->TabWord);
    fclose(file);
}

// Fungsi untuk memeriksa apakah username sudah ada
int is_username_exists(const Word *username) {
    FILE *file = fopen(TXT_FILE, "r");
    if (!file) {
        return 0; // File tidak ada, berarti username belum terdaftar
    }
    Word temp_username, temp_password;
    while (fscanf(file, "%s %s", temp_username.TabWord, temp_password.TabWord) == 2) {
        temp_username.Length = strlen(temp_username.TabWord);
        temp_password.Length = strlen(temp_password.TabWord);
        if (isKataEqual(temp_username, *username)) { // Membandingkan kata
            fclose(file);
            return 1; // Username ditemukan
        }
    }
    fclose(file);
    return 0; // Username tidak ditemukan
}

// Fungsi REGISTER
void register_user() {
    if (!session_active) {
        printf("Error: Anda harus memulai sesi terlebih dahulu dengan START.\n");
        return;
    }

    extern Word username;
    extern Word password;

    // Menggunakan Mesin Kata untuk mendapatkan input username dan password
    printf("Username: ");
    startKata(); // Mulai membaca kata
    copyKata(&currentWord, &username); // Menyalin kata ke username

    printf("Password: ");
    startKata(); // Mulai membaca kata
    copyKata(&currentWord, &password); // Menyalin kata ke password

    if (is_username_exists(&username)) {
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username.TabWord);
    } else {
        write_user_to_file(&username, &password);
        printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username.TabWord);
    }
}


// Fungsi LOGIN
void login_user() {
    if (!session_active) {
        printf("Error: Anda harus memulai sesi terlebih dahulu dengan START.\n");
        return;
    }

    if (logged_in_user.Length > 0) {  // Menggunakan logged_in_user.length untuk mengecek login status
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", logged_in_user.TabWord);
        return;
    }

    extern Word username, password;
    
    // Menggunakan Mesin Kata untuk mendapatkan input username dan password
    printf("Username: ");
    startKata(); // Mulai membaca kata
    copyKata(&currentWord, &username); // Menyalin kata ke username

    printf("Password: ");
    startKata(); // Mulai membaca kata
    copyKata(&currentWord, &password); // Menyalin kata ke password

    FILE *file = fopen(TXT_FILE, "r");
    if (!file) {
        printf("Tidak ada data pengguna terdaftar.\n");
        return;
    }

    Word temp_username, temp_password;
    int found = 0;
    while (fscanf(file, "%s %s", temp_username.TabWord, temp_password.TabWord) == 2) {
        temp_username.Length = strlen(temp_username.TabWord);
        temp_password.Length = strlen(temp_password.TabWord);
        if (isKataEqual(temp_username, username) && isKataEqual(temp_password, password)) {
            copyKata(&username, &logged_in_user); // Set pengguna yang login
            printf("Anda telah login ke PURRMART sebagai %s.\n", logged_in_user.TabWord);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Username atau password salah.\n");
    }
}

// Fungsi untuk LOGOUT
void logout_user() {
    if (logged_in_user.Length == 0) {  // Menggunakan logged_in_user.length untuk mengecek login status
        printf("Anda belum login.\n");
    } else {
        printf("Anda telah logout dari PURRMART.\n");
        logged_in_user.Length = 0; // Reset username yang login
        logged_in_user.TabWord[0] = '\0'; // Clear logged_in_user
    }
}