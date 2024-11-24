#include <stdio.h>
#include <stdlib.h>
#include "reglog.h"
#include "ADT_Mesin_Karakter.h"
#include "ADT_Mesin_Kata.h" 
#include "ADT_Kustom.h"

int session_active = 0; // Menandakan apakah sesi telah dimulai
int user_count, i;
Word logged_in_user = { "", 0 }; // Menyimpan users[i].name yang sedang login

void read_file(const char *file_name) {
    // Mulai membaca file
    startFileKata(TXT_FILE);

    // Membaca jumlah barang
    int nBarang;
    if (!EndWord && isKataInt(currentWord)) {
        nBarang = kataToInt(currentWord);
        ADVFileKata();
    }

    // Membaca data barang
    for (int i = 0; i < nBarang; i++) {
        if (EndWord) break;

        // Membaca harga
        if (isKataInt(currentWord)) {
            items[i].price = kataToInt(currentWord);
            ADVFileKata();
        }

        // Membaca nama barang
        if (!EndWord) {
            wordToString(currentWord, items[i].name);
            ADVFileKata();
        }
    }

    // Membaca jumlah user
    if (!EndWord && isKataInt(currentWord)) {
        user_count = kataToInt(currentWord);
        ADVFileKata();
    }

    // Membaca data user
    for (int i = 0; i < user_count; i++) {
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

// Fungsi untuk menulis data ke file
void write_user_to_file(User users[], int user_count) {
    startFileKata(TXT_FILE); // Membuka file database user

    if (EndWord) { // Mengecek apabila file gagal dibuka
        printf("Error: Tidak dapat membuka file %s untuk menulis data.\n", TXT_FILE);
        return;
    }

    for (int i = 0; i < user_count; i++) {
        char username[MAX_LEN] = users[i].name;
        copyKata(&currentWord, &username);
        //wordToString(username, &currentWord);  // Mengonversi Word menjadi string
        displayKata(currentWord, false);

        Word spasi = {.TabWord = " ", .Length = 1};
        displayKata(spasi, false);

        char password[MAX_LEN] = users[i].password;
        copyKata(&currentWord, &password);
        displayKata(currentWord, false);  // Menampilkan password

        Word newline = {.TabWord = "\n", .Length = 1};
        displayKata(newline, true);  // Menambahkan newline
    }
}

// Fungsi untuk memeriksa apakah username sudah ada
int is_username_exists(const User users[], int user_count, const Word *username) {
    startFileKata(TXT_FILE);

    if (EndWord) {
        return 0; // File tidak ada, berarti users[i].name belum terdaftar
    }

    Word temp_username, temp_password;

    while (!EndWord) {
        temp_username = currentWord;  // Menyimpan users[i].name yang dibaca
        ADVFileKata();  // Berpindah ke users[i].password
        temp_password = currentWord;  // Menyimpan users[i].password

        // Cek apakah users[i].name yang dibaca sama dengan users[i].name yang dicari
        if (isKataEqual(temp_username, *username)) {
            return 1; // Username ditemukan
        }

        ADVFileKata();  // Pindah ke kata berikutnya (jika ada)
    }
    return 0; // Username tidak ditemukan
}

// Fungsi REGISTER
void register_user() {
    if (!session_active) {
        printf("Error: Anda harus memulai sesi terlebih dahulu dengan START.\n");
        return;
    }

    if (user_count >= MAX_USERS) {
        printf("Error: Jumlah pengguna maksimal telah tercapai.\n");
        return;
    }

    Word username, password;
    printf("Username: ");
    startKata();
    copyKata(&currentWord, &username);  // Mengambil username

    printf("Password: ");
    startKata();
    copyKata(&currentWord, &password);  // Mengambil password

    for (int i = 0; i < user_count; i++) {
        char uname[MAX_LEN] = users[i].name;
        copyKata(&currentWord, &uname);
        if (isKataEqual(username, currentWord)) {
            printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username.TabWord);
            return;
        }
    }

    copyKata(&username, &users[user_count].name);
    copyKata(&password, &users[user_count].password);
    users[user_count].money = 0; // Nilai default saldo
    user_count++;

    write_user_to_file(users, user_count);
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username.TabWord);
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
    printf("Username: ");
    startKata();  // Membaca username
    copyKata(&currentWord, &input_username);

    printf("Password: ");
    startKata();  // Membaca password
    copyKata(&currentWord, &input_password);

    // Membuka file data user
    startFileKata(TXT_FILE);
    if (EndWord) {
        printf("Tidak ada data pengguna terdaftar.\n");
        return;
    }

    Word temp_username, temp_password;
    int current_index = 0;  // Indeks untuk membaca file

    while (!EndWord) {
        temp_username = currentWord;
        ADVFileKata();

        temp_password = currentWord;
        ADVFileKata();

        if (isKataEqual(temp_username, input_username) && isKataEqual(temp_password, input_password)) {
            copyKata(&input_username, &logged_in_user);  // Menyimpan username yang login
            printf("Anda telah login ke PURRMART sebagai %s.\n", logged_in_user.TabWord);
            return;
        }
        current_index++;
    }

    printf("Username atau password salah.\n");
}

// Fungsi untuk LOGOUT
void logout_user() {
    if (logged_in_user.Length == 0) {  // Menggunakan logged_in_user.length untuk mengecek login status
        printf("Anda belum login.\n");
    } else {
        printf("Anda telah logout dari PURRMART.\n");
        logged_in_user.Length = 0; // Reset users[i].name yang login
        logged_in_user.TabWord[0] = '\0'; // Clear logged_in_user
    }
}
