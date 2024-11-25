#ifndef REGLOG_H
#define REGLOG_H

#include "ADT_Mesin_Karakter.h"
#include "ADT_Mesin_Kata.h"
#include "ADT_Kustom.h"

// Deklarasi variabel global
int session_active;  // Menandakan apakah sesi telah dimulai
int user_count;      // Menyimpan jumlah pengguna yang terdaftar
User users[MAX_USERS]; // Array pengguna
Barang items[MAX_ITEMS]; // Array barang
Word logged_in_user;  // Menyimpan username yang sedang login

// Deklarasi konstanta
#define TXT_FILE "default.txt"  // File tempat menyimpan data pengguna

// Fungsi untuk membaca data dari file
void read_file(const char *file_name);

// Fungsi untuk menulis data pengguna ke dalam file
// void write_user_to_file(User users[], int jumlahUsers, const char *file_name);

// Fungsi untuk memeriksa apakah username sudah terdaftar
int is_username_exists(const User users[], int user_count, const Word *username);

// Fungsi REGISTER
void register_user();

// Fungsi LOGIN
void login_user();

// Fungsi LOGOUT
void logout_user();

#endif // REGLOG_H
