#include <stdio.h>
#include <stdlib.h>
#include "reglog.h"

int session_active = 0; // Menandakan apakah sesi telah dimulai
int jumlahUsers = 0, i;
Word logged_in_user = { "", 0 }; // Menyimpan users[i].name yang sedang login

// Fungsi REGISTER
void register_user(List *users, User newUser) {
    // Pemeriksaan apakah sesi sudah aktif
    if (!session_active) {
        printf("Error: Anda harus memulai sesi terlebih dahulu dengan START.\n");
        return;
    }

    // Pemeriksaan apakah jumlah pengguna sudah mencapai batas maksimal
    if (users->Count >= MAX_USERS) {
        printf("Error: Jumlah pengguna maksimal telah tercapai.\n");
        return;
    }

    char usernameStr[MAX_LEN];
    char passwordStr[MAX_LEN];

    // Input username
    printf("Username: ");
    startKata();
    wordToString(currentWord, usernameStr);

    // Input password
    printf("Password: ");
    startKata();
    wordToString(currentWord, passwordStr);

    // Memeriksa apakah username sudah ada (opsional)
    for (int i = 0; i < users->Count; i++) {
        if (compareStrings(usernameStr, users->A[i].name)) {
            printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", usernameStr);
            return;
        }
    }

    // Menyimpan data user baru
    copyString(users->A[users->Count].name, usernameStr);
    copyString(users->A[users->Count].password, passwordStr);
    users->A[users->Count].money = 0;  // Default saldo
    users->Count++;

    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", usernameStr);
}

// void register_user(char *configFile, List users) {
//     // int jumlahBarang;
//     // ListDin items;
//     if (!session_active) {
//         printf("Error: Anda harus memulai sesi terlebih dahulu dengan START.\n");
//         return;
//     }
// 
//     if (jumlahUsers >= MAX_USERS) {
//         printf("Error: Jumlah pengguna maksimal telah tercapai.\n");
//         return;
//     }
// 
//     // Word username, password;
//     // char usernameStr[MAX_LEN];
//     // char passwordStr[MAX_LEN];
//     
//     printf("Username: ");
//     startKata();
//     // input_username = currentWord;
//     char usernameStr[MAX_LEN];
//     wordToString(currentWord, usernameStr);
//     
//     printf("Password: ");
//     startKata();
//     // input_password = currentWord;
//     char passwordStr[MAX_LEN];
//     wordToString(currentWord, passwordStr);
// 
//     // Memeriksa apakah username sudah ada (opsional, tambahkan jika perlu)
//     for (int i = 0; i < users.Count; i++) {
//         if (compareStrings(usernameStr, users.A[i].name)) {
//             printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", usernameStr);
//             return;
//         }
//     }
// 
//     // Simpan data user baru
//     copyString(users.A[users.Count].name, usernameStr);
//     copyString(users.A[users.Count].password, passwordStr);
//     users.A[users.Count].money = 0;  // Default saldo
//     users.Count++;
//     // printf("%d", users.Count);
// 
//     printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", usernameStr);
//     
//     // Simpan data ke file
//     // ListDin barang; // Tambahkan argumen barang jika diperlukan
//     // barang.nEff = 0; // Misalnya, tidak ada barang saat register
//     // SAVE_TO_FILE(barang, barang.nEff, users, users.Count, configFile);
// }


// Fungsi LOGIN
int login_user(List users, Word *logged_in_user) {
    // Memeriksa apakah pengguna sudah login
    if (logged_in_user->Length > 0) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", logged_in_user->TabWord);
        return 0; // Tidak bisa login, harus logout terlebih dahulu
    }

    char usernameStr[MAX_LEN];
    char passwordStr[MAX_LEN];

    // Input username
    printf("Username: ");
    startKata();
    wordToString(currentWord, usernameStr);

    // Input password
    printf("Password: ");
    startKata();
    wordToString(currentWord, passwordStr);

    // Memeriksa username dan password
    for (int idxUser = 0; idxUser < users.Count; idxUser++) {
        if (compareStrings(usernameStr, users.A[idxUser].name) && compareStrings(passwordStr, users.A[idxUser].password)) {
            // Menyimpan username yang login
            copyString(logged_in_user->TabWord, usernameStr);
            logged_in_user->Length = stringLength(usernameStr);

            return idxUser; // Login sukses
        }
    }

    printf("Username atau password salah.\n");
    return -1; // Login gagal
}

// int login_user(List users, Word logged_in_user) {
//     if (logged_in_user.Length > 0) {
//         printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", logged_in_user.TabWord);
//         return 0;
//     }
// 
//     // Word input_username, input_password;
//     // char usernameStr[MAX_LEN];
//     // char passwordStr[MAX_LEN];
//     
//     printf("Username: ");
//     startKata();
//     // input_username = currentWord;
//     char usernameStr[MAX_LEN];
//     wordToString(currentWord, usernameStr);
//     
//     printf("Password: ");
//     startKata();
//     // input_password = currentWord;
//     char passwordStr[MAX_LEN];
//     wordToString(currentWord, passwordStr);
// 
//     // Check username and password
//     for (int idxUser = 0; idxUser < users.Count; idxUser++) {
//         if (compareStrings(usernameStr, users.A[idxUser].name) && compareStrings(passwordStr, users.A[idxUser].password)) {
//             // wordToString(input_username, logged_in_user.TabWord);
// 
//             // copyStrin(logged_in_user.TabWord, usernameStr);
//             // logged_in_user.Length = stringLength(usernameStr);
//             return idxUser;  // Login successful
//         }
//     }
//     
//     printf("Username atau password salah.\n");
//     return -1;  // Login failed
// }

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