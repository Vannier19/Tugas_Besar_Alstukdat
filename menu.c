#include <stdio.h>
#include "ADT_Mesin_Karakter.h"
#include "ADT_Mesin_Kata.h"
#include "reglog.h"

Barang items[MAX_ITEMS];
User users[MAX_USERS];

// Fungsi untuk memulai sesi
void start_session() {
    session_active = 1;
    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
    printf("Command yang tersedia: LOGIN, REGISTER, HELP\n");
}

// Fungsi untuk menampilkan HELP pada Welcome Menu
void help_welcome() {
    printf("=====[ Welcome Menu Help PURRMART ]=====\n");
    printf("START -> Untuk masuk sesi baru\n");
    printf("LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf("QUIT -> Untuk keluar dari program\n");
}

// Fungsi untuk menampilkan HELP pada Login Menu
void help_login() {
    printf("=====[ Login Menu Help PURRMART ]=====\n");
    printf("REGISTER -> Untuk melakukan pendaftaran akun baru\n");
    printf("LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
    printf("QUIT -> Untuk keluar dari program\n");
}

// Fungsi untuk menampilkan HELP pada Main Menu
void help_main() {
    printf("=====[ Menu Help PURRMART]=====\n");
    printf("WORK -> Untuk bekerja\n");
    printf("WORK CHALLENGE -> Untuk mengerjakan challenge\n");
    printf("STORE LIST -> Untuk melihat barang-barang di toko\n");
    printf("STORE REQUEST -> Untuk meminta penambahan barang\n");
    printf("STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
    printf("STORE REMOVE -> Untuk menghapus barang\n");
    printf("LOGOUT -> Untuk keluar dari sesi\n");
    printf("SAVE -> Untuk menyimpan state ke dalam file\n");
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

    while (session_active) {
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
