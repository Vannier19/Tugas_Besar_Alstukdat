#ifndef REGLOG_H
#define REGLOG_H

#include "ADT_Mesin_Karakter.h"
#include "ADT_Mesin_Kata.h"

// Deklarasi variabel global
extern int session_active;  // Menandakan apakah sesi telah dimulai
extern Word logged_in_user;  // Menyimpan username yang sedang login

// Deklarasi konstanta
#define TXT_FILE "purrmart_users.txt"  // File tempat menyimpan data pengguna

// Fungsi untuk menulis data pengguna ke dalam file
void write_user_to_file(const Word *username, const Word *password);

// Fungsi untuk memeriksa apakah username sudah terdaftar
int is_username_exists(const Word *username);

// Fungsi REGISTER
void register_user();

// Fungsi LOGIN
void login_user();


// Fungsi LOGOUT
void logout_user();

#endif // REGLOG_H