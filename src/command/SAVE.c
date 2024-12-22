#include <stdio.h>
#include "SAVE.h"

// Fungsi untuk menyimpan barang ke dalam file sesuai dengan spesifikasi
void saveBarang(ListDin listBarang, const char *filename) {
    FILE *file = fopen(filename, "a"); 
    if (file != NULL) {
        // Simpan jumlah barang
        fprintf(file, "%d\n", listBarang.nEff);

        // Simpan data barang dengan format <Harga> <Nama barang>
        for (int i = 0; i < listBarang.nEff; i++) {
            Barang b = ELMT(listBarang, i); // Ambil barang dari ListDin
            fprintf(file, "%d %s\n", b.price, b.name); // Format: <Harga> <Nama barang>
        }

        fclose(file);
    } else {
        printf("Error: Cannot open file for saving barang data.\n");
    }
}

// Fungsi untuk menyimpan data pengguna dan riwayat pembelian serta wishlist sesuai dengan spesifikasi
void saveUsers(List users, const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file != NULL) {
        // Simpan jumlah pengguna
        fprintf(file, "%d\n", users.Count); // Simpan jumlah pengguna

        // Simpan data setiap pengguna
        for (int i = 0; i < users.Count; i++) {
            User user = users.A[i];

            Stack riwayat = users.A->riwayat_pembelian;

            // Simpan jumlah riwayat pembelian pengguna
            int historyCount = LengthStack(riwayat);
            fprintf(file, "%d\n", historyCount); // Menyimpan jumlah riwayat pembelian

            // Stack sementara untuk membalikkan elemen
            Stack tempStack;
            CreateEmptyStack(&tempStack);

            // Proses elemen dari riwayat
            ItemStack item;
            while (!IsEmptyStack(riwayat)) {
                PopStack(&riwayat, &item);            // Pop dari stack riwayat
                PushStack(&tempStack, item);          // Simpan ke stack sementara
                // Format output sesuai spesifikasi
                fprintf(file, "%d %s\n", item.totalBiaya, item.item.name); 
            }

            // Kembalikan stack riwayat ke keadaan semula
            while (!IsEmptyStack(tempStack)) {
                PopStack(&tempStack, &item);
                PushStack(&riwayat, item);
            }

            ListLinier wishlist = users.A->wishlist; // Wishlist dari pengguna

            // Simpan jumlah wishlist pengguna
            int wishlistCount = NbElmt(wishlist);
            fprintf(file, "%d\n", wishlistCount); // Menyimpan jumlah wishlist
            
            addressList P;
            P = First(wishlist);
            // Simpan wishlist pengguna (format <Nama barang>)
            while (P != NilList) {
                char *w;
                w = Info(P).TabWord;
                P = Next(P);
                // Menulis nama barang ke file
                fprintf(file, "%s\n", w); // Format: <Nama barang>
            }
        }

        fclose(file);
    } else {
        printf("Error: Cannot open file for saving user data.\n");
    }
}

// Fungsi utama untuk menyimpan semua data (barang dan pengguna) ke dalam file
void save(ListDin listBarang, List users, const char *filename) {
    // Simpan data barang ke file
    saveBarang(listBarang, filename);

    // Simpan data pengguna ke file
    saveUsers(users, filename);
}