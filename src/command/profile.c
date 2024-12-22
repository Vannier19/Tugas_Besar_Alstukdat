#include <stdio.h>
#include "profile.h"

void show_profile(List users, int idxUser) {
    printf("Nama : %s\n", users.A[idxUser].name);
    // printf("Saldo: %d\n", users.A[idxUser].money);
}

// Fungsi untuk mencari index user berdasarkan username
int find_idxUser(List users, int jumlahUsers, char *username) {
    for (int i = 0; i < jumlahUsers; i++) {
        if (compareStrings(users.A[i].name, username)) {
            return i; // Mengembalikan indeks user yang ditemukan
        }
    }
    return -1; // Jika user tidak ditemukan, kembalikan -1
}

