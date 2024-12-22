#include <stdio.h>
#include "help.h"

void show_welcome_help() {
    printf("=====[ Welcome Menu Help PURRMART ]=====\n");
    printf("START -> Untuk masuk sesi baru\n");
    printf("LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf("QUIT -> Untuk keluar dari program\n");
}
void show_login_help() {
    printf("=====[ Login Menu Help PURRMART ]=====\n");
    printf("REGISTER -> Untuk melakukan pendaftaran akun baru\n");
    printf("LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
    printf("QUIT -> Untuk keluar dari program\n");
}
void show_main_menu_help() {
    printf("=====[ Main Menu Help PURRMART ]=====\n");
    printf("WORK -> Untuk bekerja\n");
    printf("WORK CHALLENGE -> Untuk mengerjakan challenge\n");
    printf("STORE LIST -> Untuk melihat barang-barang di toko\n");
    printf("STORE REQUEST -> Untuk meminta penambahan barang\n");
    printf("STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
    printf("STORE REMOVE -> Untuk menghapus barang\n");
    printf("LOGOUT -> Untuk keluar dari sesi\n");
    printf("SAVE <filename> -> Untuk menyimpan data sesi ke <filename>\n");
    printf("PROFILE -> Untuk menampilkan \n");
    printf("CART ADD <nama> <n>\n");
    printf("CART REMOVE <nama> <n>\n");
    printf("CART SHOW\n");
    printf("CART PAY\n");
    printf("HISTORY <n>\n");
    printf("WISHLIST ADD\n");
    printf("WISHLIST SWAP\n");
    printf("WISHLIST REMOVE i\n");
    printf("WISHLIST REMOVE\n");
    printf("WISHLIST CLEAR\n");
    printf("WISHLIST SHOW\n");
    printf("QUIT\n");
}