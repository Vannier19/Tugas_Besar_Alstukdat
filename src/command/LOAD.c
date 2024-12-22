#include <stdio.h>
#include "load.h"

#define MAX_LEN 100
#define MAX_ITEMS 100

// boolean START_READ_FILE(char *filename, ListDin *barang, List *users) {
//     LOAD_Barang(&filename, &barang);

//     if (!EndWord) {
//         ADVKata();
//     }
//     if (EndWord) {
//         printf("Data user tidak ditemukan.\n");
//         return false;
//     }

//     int jumlahUser = kataToInt(currentWord);
//     users->Count = jumlahUser;

//     if (jumlahUser > MAX_USERS) { 
//         printf("Jumlah user melebihi kapasitas List.\n");
//         return false;
//     }

//     for (int i = 0; i < jumlahUser; i++) {
//         // Baca uang user
//         ADVKata();
//         users->A[i].money = kataToInt(currentWord);

//         // Baca nama user
//         ADVKata();
//         wordToString(currentWord, users->A[i].name);

//         // Baca password user
//         ADVKata();
//         wordToString(currentWord, users->A[i].password);
//     }
// }

boolean LOAD_Barang(char *filename, ListDin *barang) {
    ElType Temp;

    startFileKata(filename);
    if (EndWord) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return false;
    }

    int jumlahBarang = kataToInt(currentWord);

    if (jumlahBarang > barang->capacity) {
        printf("Jumlah barang melebihi kapasitas ListDin.\n");
        return false;
    }
    
    for (int i = 0; i < jumlahBarang; i++) {
        // Baca harga barang
        ADVFileKata();
        // ADVFileKata();
        Temp.price = kataToInt(currentWord);
        // printf("Harga barang: %d\n", Temp.price);

        // Baca nama barang
        ADVFileKata();
        wordToString(currentWord, Temp.name);
        // printf("Nama barang: %s\n", Temp.name);
        insertLast(barang, Temp);
    }
    return true;
}

boolean LOAD_User(char *filename, List *users) {
    if (!EndWord) {
        ADVKata();
    }

    if (EndWord) {
        printf("Data user tidak ditemukan.\n");
        return false;
    }

    int jumlahUser = kataToInt(currentWord);
    users->Count = jumlahUser;
    // printf("Jumlah user: %d\n", jumlahUser);

    if (jumlahUser > MAX_USERS) {  // Check against MAX_USERS instead of Count
        printf("Jumlah user melebihi kapasitas List.\n");
        return false;
    }

    for (int i = 0; i < jumlahUser; i++) {
        // Baca uang user
        ADVKata();
        users->A[i].money = kataToInt(currentWord);
        // printf("Uang user: %d\n", users->A[i].money);

        // Baca nama user
        ADVKata();
        wordToString(currentWord, users->A[i].name);
        // printf("Nama user: %s\n", users->A[i].name);

        // Baca password user
        ADVKata();
        wordToString(currentWord, users->A[i].password);
        // printf("Password user: %s\n", users->A[i].password);

        //skip history
        ADVKata();
        int jumlahHistoryUser = kataToInt(currentWord);
        for (int j = 0; j < jumlahHistoryUser; j++) {
            ADVFileKata();
            ADVFileKata();
        }

        //skip wishlist
        ADVFileKata();
        int jumlahWishlist = kataToInt(currentWord);
        for (int j = 0; j < jumlahWishlist; j++) {
            ADVFileKata();
        }
    }

    return true;
}

boolean LOAD_History(char *filename, User users[], int jumlahUser, Stack *history) {
    startFileKata(filename);
    if (EndWord) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return false;
    }

    int jumlahBarang = kataToInt(currentWord);
    for (int i = 0; i < jumlahBarang; i++) {
        ADVFileKata();
        ADVFileKata();
    }

    ADVFileKata();
    if (kataToInt(currentWord) != jumlahUser) {
        printf("Jumlah user tidak sesuai.\n");
        return false;
    }

    for (int i = 0; i < jumlahUser; i++) {
        CreateEmptyStack(&users[i].riwayat_pembelian);

        // skip user
        ADVFileKata(); 
        // printf("%s\n", currentWord.TabWord);
        ADVFileKata();
        // printf("%s\n", currentWord.TabWord); 

        ADVKata();
        // printf("%s\n", currentWord.TabWord);
        int jumlahHistoryUser = kataToInt(currentWord);
        // printf("Jumlah pembelian user %s: %d\n", users[i].name, jumlahHistoryUser);

        for (int j = 0; j < jumlahHistoryUser; j++) {
            ItemStack historyItem;

            ADVFileKata();
            // printf("%s\n", currentWord.TabWord);
            if (!EndWord) {
                historyItem.item.price = kataToInt(currentWord);
            }

            // Baca nama item
            ADVFileKata();
            // printf("%s\n", currentWord.TabWord);
            if (!EndWord) {
                wordToString(currentWord, historyItem.item.name);
            }

            PushStack(&users[i].riwayat_pembelian, historyItem);
        }
        // skip wishlist
        ADVFileKata();
        int jumlahWishlist = kataToInt(currentWord);
        for (int k = 0; k < jumlahWishlist; k++) {
            ADVFileKata();
        }
        // printf("Daftar pembelian user %s:\n", users[i].name);
        // printf("Jumlah pembelian: %d\n", jumlahHistoryUser);
    }

    return true;
}

boolean LOAD_Wishlist(char *filename, User users[], int jumlahUser, ListLinier *wishlist) {
    startFileKata(filename);
    if (EndWord) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return false;
    }

    int jumlahBarang = kataToInt(currentWord);
    for (int i = 0; i < jumlahBarang; i++) {
        ADVFileKata();
        ADVFileKata();
    }

    ADVFileKata();
    if (kataToInt(currentWord) != jumlahUser) {
        printf("Jumlah user tidak sesuai.\n");
        return false;
    }

    for (int i = 0; i < jumlahUser; i++) {
        CreateEmptyLinier(&users[i].wishlist);

        ADVFileKata(); // Skip money
        ADVFileKata(); // Skip username
        // ADVFileKata(); // Skip password

        // Skip history
        ADVKata();
        int jumlahHistoryUser = kataToInt(currentWord);
        for (int j = 0; j < jumlahHistoryUser; j++) {
            ADVFileKata();
            ADVFileKata();
        }

        // Read wishlist
        ADVFileKata();
        int jumlahWishlist = kataToInt(currentWord);
        // printf("Jumlah wishlist user %s: %d\n", users[i].name, jumlahWishlist);

        for (int k = 0; k < jumlahWishlist; k++) {
            ADVFileKata();
            addressList newNode = Alokasi(currentWord);
            if (newNode != NilList) {
                InsertLast(&users[i].wishlist, newNode);
            }
        }
    }

    return true;
}

boolean LOAD(char *filename, ListDin *barang, List *users, Stack *history, ListLinier *wishlist) {
    if (!LOAD_Barang(filename, barang)) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return false;
    }

    if (!LOAD_User(filename, users)) {
        printf("Data user tidak ditemukan.\n");
        return false;
    }

    if (!LOAD_History(filename, users->A, users->Count, history)) {
        printf("Riwayat pembelian gagal dimuat.\n");
        return false;
    }

    if (!LOAD_Wishlist(filename, users->A, users->Count, wishlist)) {
        printf("Wishlist gagal dimuat.\n");
        return false;
    }
    printf("\nSave file berhasil dibaca. PURRMART berhasil dijalankan.\n\n");
    return true;
}

// int main() {
//     ListDin barang;
//     List users;

//     CreateListDin(&barang, MAX_ITEMS);
//     CreateListUser(&users);

//     if (LOAD("konfigurasi.txt", &barang, &users)) {
//         printf("Semua data berhasil dimuat!\n");
        
//     } else {
//         printf("Gagal memuat beberapa data.\n");
//         return 1;
//     }
//     // printf("Jumlah barang: %d\n", barang.nEff);

//     // Bebasin memori
//     dealocateList(&barang);

//     return 0;
// }