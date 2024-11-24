#include <stdio.h>
#include "ADT_Mesin_Karakter.h"
#include "ADT_Mesin_Kata.h"
#include "reglog.h"

// Fungsi untuk memulai sesi
void start_session() {
    printf(">> START\n");
    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
    printf("Command yang tersedia: LOGIN, REGISTER, HELP\n");
}

// Fungsi untuk menampilkan HELP pada Welcome Menu
void help_welcome() {
    printf(">> HELP\n");
    printf("=====[ Welcome Menu Help PURRMART ]=====\n");
    printf("START -> Untuk masuk sesi baru\n");
    printf("LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf("QUIT -> Untuk keluar dari program\n");
}

// Fungsi untuk menampilkan HELP pada Login Menu
void help_login() {
    printf(">> HELP\n");
    printf("=====[ Login Menu Help PURRMART ]=====\n");
    printf("REGISTER -> Untuk melakukan pendaftaran akun baru\n");
    printf("LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
    printf("QUIT -> Untuk keluar dari program\n");
}


// Fungsi untuk menampilkan Welcome Menu
void welcome() {
    printf("Selamat datang di PURRMART! Pilih command untuk melanjutkan:\n");
    printf("Command yang tersedia: START, LOAD, HELP\n");
}

// Fungsi untuk menangani QUIT
void quit_program() {
    char save_choice;
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");

    start(); // Inisialisasi Mesin Karakter untuk membaca input
    save_choice = getCC();
    ADV(); // Pindahkan ke karakter berikutnya (meskipun tidak digunakan)

    if (save_choice == 'Y' || save_choice == 'y') {
        // save_data(); // Implementasi fungsi penyimpanan
    }
    printf("Kamu keluar dari PURRMART.\n");
    printf("Dadah ^_^/\n");
}

// Fungsi utama
int main() {
    Word command;

    // Menampilkan Welcome Menu
    welcome();

    while (1) {
        printf(">> ");
        startKata(); // Memulai Mesin Kata
        command = currentWord;

        if (isKataEqual(command, (Word){"START", 5})) {
            start_session();
            break; // Pindah ke sesi berikutnya
        } else if (isKataEqual(command, (Word){"LOAD", 4})) {
            printf(">> LOAD\n");
            printf("Data pengguna berhasil dimuat.\n");
            break; // Pindah ke sesi berikutnya
        } else if (isKataEqual(command, (Word){"HELP", 4})) {
            help_welcome();
        } else if (isKataEqual(command, (Word){"QUIT", 4})) {
            quit_program();
            return 0;
        } else {
            printf("Command tidak dikenali. Gunakan START, LOAD, atau HELP.\n");
        }
    }

    while (1) {
        printf(">> ");
        startKata(); // Memulai Mesin Kata
        command = currentWord;

        if (isKataEqual(command, (Word){"REGISTER", 8})) {
            register_user();
        } else if (isKataEqual(command, (Word){"LOGIN", 5})) {
            login_user();
        } else if (isKataEqual(command, (Word){"HELP", 4})) {
            help_login();
        } else if (isKataEqual(command, (Word){"QUIT", 4})) {
            quit_program();
            return 0;
        } else {
            printf("Command tidak dikenali. Gunakan REGISTER, LOGIN, HELP, atau QUIT.\n");
        }
    }

    return 0;
}