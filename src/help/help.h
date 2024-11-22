#include <stdio.h>
#ifndef HELP
#define HELP
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
    printf("=====[ Menu Help PURRMART ]=====\n");
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

#endif
