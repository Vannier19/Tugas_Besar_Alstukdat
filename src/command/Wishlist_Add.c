#include "ADT_Array_Dinamis.h"
#include "ADT_Kustom.h"
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>


void wishlistAdd(ListDin *barangList, List *wishlist, Word namaBarang) {
    // Cek apakah barang ada di dalam List Dinamis
    boolean found = false;
    for (int i = 0; i < NEFF(*barangList); i++) {
        if (manual_strcmp(ELMT(*barangList, i).name, namaBarang.TabWord) == 0) {
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Tidak ada barang dengan nama %s!\n", namaBarang.TabWord);
        return;
    }

    // Cek apakah barang sudah ada di dalam wishlist
    if (Search(*wishlist, namaBarang)) {
        printf("%s sudah ada di wishlist!\n", namaBarang.TabWord);
        return;
    }

    // Tambahkan barang ke wishlist
    InsVLast(wishlist, namaBarang);
    printf("Berhasil menambahkan %s ke wishlist!\n", namaBarang.TabWord);
}

// int main() {
//     List wishlist;
//     Word namaBarang;
//     ListDin barangList;

//     // Inisialisasi list
//     CreateListDin(&barangList, 100 );
//     CreateEmptyLinier(&wishlist);
    
//     // Adding 3 elements to the list
//     Barang b1 = {"Item1", 10};
//     Barang b2 = {"Item2", 20};
//     Barang b3 = {"Item3", 30};
//     insertLast(&barangList, b1);
//     insertLast(&barangList, b2);
//     insertLast(&barangList, b3);

//     // Printing the list
//     printList(barangList);

//     // Contoh barang yang sudah ada di list barang
//     Word barang1 = {"Laptop", 6};
//     Word barang2 = {"Smartphone", 10};
//     Word barang3 = {"Tablet", 6};
    
//     // Menambahkan barang ke wishList
//     InsVLast(&wishlist, barang1);
//     InsVLast(&wishlist, barang2);
//     InsVLast(&wishlist, barang3);

//     // Menampilkan barang yang ada di list barang
//     printf("List Barang: ");
//     PrintInfo(wishlist);
//     printf("\n");

//     // Menambahkan barang ke wishlist
//     printf("Masukkan nama barang untuk ditambahkan ke wishlist: ");
//     startKata();  // Memulai pengambilan input dari mesin kata
//     while (!EndWord) {
//         // Memasukkan nama barang dari input pengguna ke wishlist jika ada di barangList
//         wishlistAdd(&barangList, &wishlist, currentWord);

//         // Menunggu input barang selanjutnya
//         printf("Masukkan nama barang berikutnya (atau tekan enter untuk selesai): ");
//         ADVKata();
//     }

//     // Menampilkan wishlist setelah penambahan barang
//     printf("Wishlist: ");
//     PrintInfo(wishlist);
//     printf("\n");

//     return 0;
// }

