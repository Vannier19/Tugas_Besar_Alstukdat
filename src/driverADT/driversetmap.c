#include <stdio.h>
#include "../boolean.h"
#include "../ADT/ADT_Map.h"
#include "../ADT/ADT_Kustom_Barang.h"
#include "../ADT/ADT_Mesin_Kata.h"
#include "../ADT/ADT_List_Linier.h"

int main() {
    // Deklarasi variabel
    Map M;
    Barang B1, B2;

    // Membuat Map kosong
    CreateEmptyMap(&M);
    printf("Map telah dibuat kosong.\n");

    // Mengecek apakah Map kosong
    if (IsEmptyMap(M)) {
        printf("Map kosong.\n");
    } else {
        printf("Map tidak kosong.\n");
    }

    // Inisialisasi Barang B1 dan B2
    manual_strcpy(B1.name, "Barang1");
    B1.price = 10000;

    manual_strcpy(B2.name, "Barang2");
    B2.price = 20000;

    // Menambahkan Barang ke Map
    InsertMap(&M, B1, 5);
    InsertMap(&M, B2, 3);
    printf("Dua barang telah ditambahkan ke Map.\n");

    // Menampilkan isi Map
    printf("Isi Map:\n");
    PrintMap(M);

    // Mengecek apakah Barang ada dalam Map
    if (IsMemberMap(M, B1)) {
        printf("Barang1 terdapat dalam Map.\n");
    } else {
        printf("Barang1 tidak terdapat dalam Map.\n");
    }

    // Menghapus Barang dari Map
    DeleteMap(&M, B1);
    printf("Barang1 telah dihapus dari Map.\n");

    // Menampilkan isi Map setelah penghapusan
    printf("Isi Map setelah penghapusan:\n");
    PrintMap(M);

    // Mencari Barang berdasarkan Total
    Barang B_found;
    findMap(M, 3, &B_found);
    if (B_found.name[0] != '\0') {
        printf("Barang ditemukan: %s dengan harga %d\n", B_found.name, B_found.price);
    } else {
        printf("Barang dengan total tertentu tidak ditemukan.\n");
    }

    return 0;
}
