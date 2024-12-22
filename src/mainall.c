#include <stdio.h>
#include <stdlib.h>
#include "ADT/ADT_Mesin_Karakter.h"
#include "ADT/ADT_Mesin_Kata.h"
#include "ADT/ADT_Queue.h"
#include "ADT/ADT_List_Linier.h"
#include "ADT/ADT_Array_Dinamis.h"
#include "command/reglog.h"
#include "command/work.h"
#include "command/store_req.h"
#include "command/store_supply.h"
#include "command/store_remove.h"
#include "command/store_list.h"
#include "command/SAVE.h"
#include "command/help.h"
#include "command/load.h"
#include "command/tebak_angka.h"
#include "command/wordl3.h"
#include "command/profile.h"
#include "command/history.h"
#include "command/Wishlist_Clear.c"
#include "command/Wishlist_Remove_i.c"
#include "command/Wishlist_Remove.c"
#include "command/Wishlist_Show.c"
#include "command/Wishlist_Swap.c"
#include "command/Wishlist_Add.c"
#include "command/Cart.c"
#include "ascii.c"

#define MAX_COMMAND_LENGTH 100

void gabungKata(char kata1[], char kata2[], char hasil[]) {
    int i = 0, j = 0;

    // Salin kata pertama ke hasil
    while (kata1[i] != '\0') {
        hasil[i] = kata1[i];
        i++;
    }

    // Salin kata kedua ke hasil
    while (kata2[j] != '\0') {
        hasil[i] = kata2[j];
        i++;
        j++;
    }

    // Tambahkan null-terminator di akhir string
    hasil[i] = '\0';
}

void daftarMenu() {
    printf("\n%-25s %-25s\n", "WORK", "CART ADD <nama> <n>");
    printf("%-25s %-25s\n", "WORK CHALLENGE", "CART REMOVE <nama> <n>");
    printf("%-25s %-25s\n", "STORE LIST", "CART SHOW");
    printf("%-25s %-25s\n", "STORE REQUEST", "CART PAY");
    printf("%-25s %-25s\n", "STORE SUPPLY", "WISHLIST ADD");
    printf("%-25s %-25s\n", "STORE REMOVE", "WISHLIST SWAP");
    printf("%-25s %-25s\n", "PROFILE", "WISHLIST REMOVE <i>");
    printf("%-25s %-25s\n", "HISTORY <n>", "WISHLIST REMOVE");
    printf("%-25s %-25s\n", "LOGOUT", "WISHLIST CLEAR");
    printf("%-25s %-25s\n", "SAVE <filename>", "WISHLIST SHOW");
}

void mainMenu() {
    //ascii purmrmart
    // welcomeAscii();
    // dibawahnya ada tulisan masukkan HELP untuk menampilkan daftar main menu

    printf("\n>> Masukkan perintah: ");
}

int main() {
    // Deklarasi variabel global
    Word command;
    Queue requestQueue;
    ListDin barang;
    List users; 
    ListLinier wishlist;
    Stack history;
    Map cart;
    Barang item;
    User user;
    Word name;

    char filename[MAX_COMMAND_LENGTH];
    // char fullPathFile[MAX_COMMAND_LENGTH];
    char pathFile[] = "../save/";
    char inputan[MAX_COMMAND_LENGTH];
    char quitStatus = 'N';
    char *kata[4];
    int hanyaStart = -99;
    int saldo = 0;
    int session = 1; 
    int jumlahBarang;
    int jumlahUsers = 0;
    int quantity;
    int idxUser;
    int jumlahSpasi;

    // Deklarasi stuktur data
    CreateQueue(&requestQueue);
    CreateListDin(&barang, 100);
    CreateListUser(&users);
    CreateEmptyStack(&history);
    CreateEmptyLinier(&wishlist);

    // printf("\n=====[ Welcome to PURRMART ]=====\n\n");
    welcomeAscii();
    while (quitStatus == 'N') {
        if (session == 1) {
            printf("START\n");
            printf("LOAD <filename>\n");
            printf("HELP\n");
            printf("QUIT\n\n");
            printf(">> Masukkan perintah: ");

            startKalimat();
            wordToString(currentWord, inputan);
            for (int i = 0; i < 4; i++) {
                kata[i] = (char *)malloc(50 * sizeof(char));
                if (kata[i] == NULL) {
                    printf("Error: gagal mengalokasikan memori\n");
                    return 1;
                }
            }
            split4Kata(inputan, kata);

            if (comparePanjangString(kata[0], "START") || comparePanjangString(kata[0], "start")) {
                if (!session_active) {
                    session_active = true;

                    if (users.Count == 0) {
                        hanyaStart = 1;
                        LOAD_Barang("default.txt", &barang);
                        printf("\nSesi dimulai. Silakan melakukan login atau register.\n");
                    }
                    else {
                        hanyaStart = 0;
                        printf("\nSesi dimulai. Silakan melakukan login atau register.\n");
                    }
                }
                else {
                    printf("Sesi sudah dimulai.\n");
                }
                session = 2;
            } 
            else if (comparePanjangString(kata[0], "LOAD") || comparePanjangString(kata[0], "load")) {
                if (kata[1] != '\0') {
                    gabungKata(pathFile, kata[1], filename);
                    LOAD(filename, &barang, &users, &history, &wishlist);
                } else {
                    printf("\nHarap masukkan perintah yang valid, yaitu LOAD <filename>.\n");
                }
            } 
            else if (comparePanjangString(kata[0], "HELP") || comparePanjangString(kata[0], "help")) {
                printf("\n");
                show_welcome_help();
            } 
            else if (comparePanjangString(kata[0], "QUIT") || comparePanjangString(kata[0], "quit")) {
                printf("\nTerima kasih telah menggunakan PURRMART. Sampai jumpa!\n\n");
                quitStatus == 'Y';
                exit(0);
            } 
            else {
                printf("\nPerintah tidak valid! Silakan coba lagi.\n");
            }
        } else if (session == 2) {
            printf("\n=====[ Authentication Menu ]=====\n");
            printf("REGISTER\n");
            printf("LOGIN\n");
            printf("QUIT\n");
            printf("\n>> Masukkan nama perintah: ");
            
            startKalimat();

            if (compareKata(currentWord, "REGISTER") || compareKata(currentWord, "register")) {
                printf("\n");
                hanyaStart = 0;
                // LOAD("konfigurasi.txt", &barang, &users, &history, &wishlist);
                register_user(&users, user);
            } 
            else if (compareKata(currentWord, "LOGIN") || compareKata(currentWord, "login")) {
                printf("\n");
                if (hanyaStart == 1) {
                    printf("\nMaaf kamu tidak bisa melakukan login karena kamu tidak membaca file apapun.\nSilahkan register untuk melanjutan.\n");
                }
                else {
                    idxUser = login_user(users, &logged_in_user);
                    if (idxUser != -1) {
                        session = 3;
                        printf("\nLogin berhasil!");
                        printf("\nSelamat menikmati waktumu di PURRMART %s\n", users.A[idxUser].name);
                        saldo = users.A[idxUser].money;
                    }
                }
            } else if (compareKata(currentWord, "QUIT") || compareKata(currentWord, "quit")) {
                printf("\nApakah kamu ingin menyimpan data sesi sekarang? (Y/N): ");
                startKalimat(); 
                if (compareKata(currentWord, "N") || compareKata(currentWord, "n")) {
                    printf("\nTerima kasih telah menggunakan PURRMART. Sampai jumpa!\n\n");
                    exit(0);
                }
                else if (compareKata(currentWord, "Y") || compareKata(currentWord, "y")) {
                    printf("Masukkan nama file: ");
                    startKata();
                    char filename[30];
                    wordToString(currentWord, filename);
                    save(barang, users, filename);
                }
                else{
                    printf("\nPerintah tidak valid! Silakan coba lagi.");
                }
            }
            else {
                printf("Perintah tidak valid! Silakan coba lagi.\n");
            }
        } else if (session == 3) {
            printf("\n=========================[ Main Menu ]===========================\n");
            printf("> MASUKKAN \"DAFTAR MENU\" ATAU \"HELP\" UNTUK MENU YANG TERSEDIA <\n");

            mainMenu();
            startKalimat(); 

            wordToString(currentWord, inputan);
            for (int i = 0; i < 4; i++) {
                kata[i] = (char *)malloc(50 * sizeof(char));
                if (kata[i] == NULL) {
                    printf("Error: gagal mengalokasikan memori\n");
                    return 1;
                }
            }
            split4Kata(inputan, kata);            

            if (comparePanjangString(kata[0], "LOGOUT") || comparePanjangString(kata[0], "logout")) {
                printf("\n");
                logout_user();
                session = 2; 
            }

            else if (comparePanjangString(kata[0], "WORK") || comparePanjangString(kata[0], "work")) {
                if (comparePanjangString(kata[1], "CHALLENGE") || comparePanjangString(kata[1], "challenge")) {
                    printf("Masukkan tantangan yang ingin dimainkan (1. Tebak Angka, 2. W0RDL3): ");
                    startKalimat(); 
                    int challengeChoice = kataToInt(currentWord);
                    if (challengeChoice == 1) {
                        printf("\n");
                        tebak_angka_game(&saldo);
                    } else if (challengeChoice == 2) {
                        printf("\n");
                        playGame(&saldo);
                    } else {
                        printf("Pilihan tidak valid!\n");
                    }
                } 
                else if ((!comparePanjangString(kata[1], "CHALLENGE")) || (!comparePanjangString(kata[0], "challenge"))) {
                    printf("\n");
                    work(&saldo);
                    printf("Saldo Anda saat ini: %d rupiah\n", saldo);
                }
            }

            else if (comparePanjangString(kata[0], "STORE") || comparePanjangString(kata[0], "store")) {
                if (comparePanjangString(kata[1], "LIST") || comparePanjangString(kata[1], "list")) {
                    printf("\n");
                    store_list(barang);
                }
                else if (comparePanjangString(kata[1], "REQUEST") || comparePanjangString(kata[1], "request")) {
                    printf("\n");
                    storeRequest(&requestQueue, barang);
                }
                else if (comparePanjangString(kata[1], "SUPPLY") || comparePanjangString(kata[1], "supply")) {
                    printf("\n");
                    storeSupply(&requestQueue, &barang);
                }
                else if (comparePanjangString(kata[1], "REMOVE") || comparePanjangString(kata[1], "remove")) {
                    printf("\n");
                    store_remove(&barang);
                }
            }
            else if (comparePanjangString(kata[0], "SAVE") || comparePanjangString(kata[0], "save")) {
                save(barang, users, kata[1]);
            }
            else if (comparePanjangString(kata[0], "PROFILE") || comparePanjangString(kata[0], "profile")) {
                printf("\n");
                show_profile(users, idxUser);
                printf("Saldo : %d\n", saldo);
            }
            else if (comparePanjangString(kata[0], "WISHLIST") || comparePanjangString(kata[0], "wishlist")) {
                wishlist = users.A[idxUser].wishlist;
                if (comparePanjangString(kata[1], "ADD") || comparePanjangString(kata[1], "add")) {
                    printf("\n");
                    int jumlahBarangWishlist;
                    store_list(barang);
                    printf("\nBerapa banyak barang yang ingin Anda tambahkan ke wishlist? ");
        
                    // Membaca jumlah barang yang ingin dimasukkan ke wishlist menggunakan Mesin Karakter dan Mesin Kata
                    startKalimat();  // Mulai membaca kata pertama untuk jumlah wishlist
                    jumlahBarangWishlist = kataToInt(currentWord); // Mengonversi kata menjadi integer (jumlah wishlist)
                    Wishlist_Show(wishlist);
                    for (int i = 0; i < jumlahBarangWishlist; i++) {
                    printf("\nMasukkan nama barang untuk ditambahkan ke wishlist: ");
            
                    // Membaca nama barang menggunakan mesin kata
                    Word barangInput;
                    startKalimat();
            
                    // Mengambil kata pertama (nama barang)
                    barangInput = currentWord;
            
                    // Mencari apakah barang yang dimasukkan ada dalam daftar barang
                    int ditemukan = 0;
                    for (int j = 0; j < barang.nEff; j++) {
                    if (manual_strcmp(barangInput.TabWord, barang.buffer[j].name) == 0) {
                    // Menambahkan barang yang ditemukan ke wishlist

                    wishlistAdd(&barang, &wishlist, barangInput);
                    ditemukan = 1;
                    break;
                }
                }
                if (ditemukan == 0) {
                printf("Barang tidak ditemukan dalam daftar barang!\n");
                }

                }
                printf("\nWishlist Anda:\n");
                Wishlist_Show(wishlist);
                    
                }
                else if (comparePanjangString(kata[1], "SWAP") || comparePanjangString(kata[1], "swap")) {
                    printf("\n");
                    int idx1;
                    if (isNumString(kata[2])) {
                        idx1 = stringToInt(kata[2]);
                    }

                    int idx2;
                    if (isNumString(kata[3])) {
                        idx2 = stringToInt(kata[3]);
                    }
                    // Melakukan swap barang dalam wishlist
                    Wishlist_Swap(&wishlist, idx1, idx2);
        
                    // Menampilkan wishlist setelah swap
                    printf("\nWishlist setelah swap:\n");
                    Wishlist_Show(wishlist);
                    printf("\n");
                }
                else if (comparePanjangString(kata[1], "REMOVE") || comparePanjangString(kata[1], "remove")) {
                    if (isNumString(kata[2])) {
                        int idx1 = stringToInt(kata[2]); 
                        Wishlist_Remove_i(&wishlist, idx1);
                        printf("\nWishlist setelah menghapus barang pada indeks ke-%d:\n", idx1);
                        Wishlist_Show(wishlist);
                    }
                    else if (comparePanjangString(kata[2], '\0')){ // manggil wishlist remove
                        Wishlist_Show(wishlist);
                        printf("\nMasukkan nama barang yang akan dihapus: ");
                        startKalimat();
                        wishlistRemove(&wishlist, currentWord);
                    }
                    else {
                        printf("Perintah tidak valid! Silakan coba lagi.\n");
                    }
                }
                else if (comparePanjangString(kata[1], "CLEAR") || comparePanjangString(kata[1], "clear")) {
                    printf("\n");
                    wishlistClear(&wishlist);
                    printf("\nWishlist setelah di-clear:\n");
                    Wishlist_Show(wishlist);
                }
                else if (comparePanjangString(kata[1], "SHOW") || comparePanjangString(kata[1], "show")) {
                    printf("\nWishlist saat ini:\n");
                    Wishlist_Show(wishlist);
                }
            }
            else if (comparePanjangString(kata[0], "HISTORY") || comparePanjangString(kata[0], "history")) {
                printf("\n");
                if (isNumString(kata[1])) {
                    int nHistory = stringToInt(kata[1]);
                    showHistory(&users.A[idxUser].riwayat_pembelian, nHistory);
                }
            }
            else if (comparePanjangString(kata[0], "CART") || comparePanjangString(kata[0], "cart")) {
                if (comparePanjangString(kata[1], "ADD") || comparePanjangString(kata[1], "add")) {
                    printf("\n");
                    store_list(barang);
                    Word itemName = stringToWord(kata[2]);
                    int angka;
                    if (isNumString(kata[3])) {
                        angka = stringToInt(kata[3]);
                    } 
                    CartAdd(&cart, barang, itemName, angka);
                }
                else if (comparePanjangString(kata[1], "REMOVE") || comparePanjangString(kata[1], "remove")) {
                    printf("\n");
                    CartShow(&cart);
                    Word barangRemove = stringToWord(kata[2]);
                    int jumlahRemove;
                    if (isNumString(kata[3])) {
                        jumlahRemove = stringToInt(kata[3]);
                    }

                    Barang temp;
                    copyString(temp.name, barangRemove.TabWord);
                    for (int i = 0; i < barang.nEff; i++) {
                        if (manual_strcmp(temp.name, barang.buffer[i].name) == 0) {
                            temp.price = barang.buffer[i].price;
                            break;
                        }
                    }
                    CartRemove(&cart, temp, barangRemove, jumlahRemove);
                    CartShow(&cart);
                }
                else if (comparePanjangString(kata[1], "SHOW") || comparePanjangString(kata[1], "show")) {
                    printf("\n");
                    CartShow(&cart);
                }
                else if (comparePanjangString(kata[1], "PAY") || comparePanjangString(kata[1], "pay")) {
                    printf("\n");
                    printf("\nSaldo awal: %d\n", saldo);
                    user.money = saldo;
                    user.keranjang = cart;

                    Stack historyItem;
                    for (int i = 0; i < cart.Count; i++) {
                        copyString(historyItem.items[i].item.name, cart.Elmt[i].Item.name);
                        historyItem.items[i].totalBiaya = cart.Elmt[i].Total;
                        // Push(&history, historyItem);
                    }
                    //AddToHistory(&users.A[idxUser].riwayat_pembelian, &historyItem);
                    CartPay(&user);
                    users.A[idxUser].money = user.money; 
                    saldo = user.money;

                    // history = user.riwayat_pembelian;
                    // int jumlahhistory = history.TOP + 1;
                    // CreateEmptyMap(&users.A[idxUser].keranjang);
                    // printf("\nDaftar history sekarang:\n");
            
                    showHistory(&users.A[idxUser].riwayat_pembelian, 999999);
                    printf("\nSaldo akhir: %d\n", saldo);
                }
            }
            else if (comparePanjangString(kata[0], "HELP") || comparePanjangString(kata[0], "help")) {
                printf("\n");
                show_main_menu_help();
            } 
            else if (comparePanjangString(kata[0], "QUIT") || comparePanjangString(kata[0], "quit")) {
                printf("\nApakah kamu ingin menyimpan data sesi sekarang? (Y/N): ");
                startKalimat(); 
                if (compareKata(currentWord, "N") || compareKata(currentWord, "n")) {
                    printf("\nTerima kasih telah menggunakan PURRMART. Sampai jumpa!\n\n");
                    exit(0);
                }
                else if (compareKata(currentWord, "Y") || compareKata(currentWord, "y")) {
                    printf("Masukkan nama file: ");
                    startKata();
                    char filename[30];
                    wordToString(currentWord, filename);
                    save(barang, users, filename);
                }
                else{
                    printf("\nPerintah tidak valid! Silakan coba lagi.");
                }
            }
            else if (comparePanjangString(kata[0], "DAFTAR") || comparePanjangString(kata[0], "daftar")) {
                if (comparePanjangString(kata[1], "MENU") || comparePanjangString(kata[1], "menu")) {
                    daftarMenu();
                }
            }
            else {
                printf("Perintah tidak valid! Silakan coba lagi.\n");
            }
        }
    }

    // Save final state before exit
    // save(barang, jumlahBarang, users, jumlahUsers, filename);
    // printf("Terima kasih telah menggunakan PURRMART. Sampai jumpa!\n");
    return 0;
}