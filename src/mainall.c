#include <stdio.h>
#include <stdlib.h>
#include "reglog.h"
#include "work.h"
#include "store_req.h"
#include "store_supply.h"
#include "store_remove.h"
#include "store_list.h"
#include "SAVE.c"
#include "help.c"
#include "LOAD.c"
#include "ADT_Mesin_Karakter.h"
#include "ADT_Mesin_Kata.h"
#include "tebak_angka.h"
#include "wordl3.h"

#define MAX_COMMAND_LENGTH 100

// ascii_art = 

void mainMenu() {
    printf("=====[ Main Menu PURRMART ]=====\n");
    printf("WORK\n");
    printf("WORK CHALLENGE\n");
    printf("STORE LIST\n");
    printf("STORE REQUEST\n");
    printf("STORE SUPPLY\n");
    printf("STORE REMOVE\n");
    printf("LOGOUT\n");
    printf("SAVE <filename>\n");
    printf("QUIT\n");
    printf("Masukkan nama perintah: ");
}

int main() {
    Word command;
    Queue requestQueue;
    ListDin store;
    Barang barang[MAX_ITEMS];
    User users[MAX_USERS];

    char filename[MAX_COMMAND_LENGTH];
    char quit = 'N';
    int saldo = 0;
    int session = 1; 
    int jumlahBarang;
    int jumlahUsers;

    CreateQueue(&requestQueue);
    CreateListDin(&store, 10);

    while (quit != 'Y') {
        if (session == 1) {
            printf("\n=====[ Welcome to PURRMART ]=====\n");
            printf("START\n");
            printf("LOAD <filename>\n");
            printf("HELP\n");
            printf("QUIT\n");
            printf("Masukkan nama perintah: ");
            
            startKata();
            
            if (compareKata(currentWord, "START")) {
                printf("Sesi dimulai. Silakan login atau register.\n");
                session = 2;
            } else if (compareKata(currentWord, "LOAD")) {
    ADVKata();  
    wordToString(currentWord, filename);
    if (LOAD_Barang(filename, barang, &jumlahBarang) && LOAD_User(filename, users, &jumlahUsers)) {
        printf("Data berhasil dimuat.\n");
    } else {
        printf("Gagal memuat data.\n");
    }


            } else if (compareKata(currentWord, "HELP")) {
                printf("\n");
                show_welcome_help();
            } else if (compareKata(currentWord, "QUIT")) {
                printf("Apakah Anda yakin ingin keluar? (Y/N): ");
                startKata(); 
                if (compareKata(currentWord, "Y")) {
                    quit = 'Y';
                } else {
                    quit = 'N';
                }
            } else {
                printf("Perintah tidak valid! Silakan coba lagi.\n");
            }
        } else if (session == 2) {
    printf("\n=====[ Welcome to PURRMART ]=====\n");
    printf("REGISTER\n");
    printf("LOGIN\n");
    printf("LOGOUT\n");
    printf("QUIT\n");
    printf("\nMasukkan nama perintah: ");
    
    startKata(); 

    if (compareKata(currentWord, "REGISTER")) {
        printf("\n");
        register_user();
    } else if (compareKata(currentWord, "LOGIN")) {
        printf("\n");
        login_user(jumlahUsers); 
        session = 3; 
    } else if (compareKata(currentWord, "LOGOUT")) {
        printf("\n");
        logout_user();
    } else if (compareKata(currentWord, "QUIT")) {
        printf("\n");
        printf("Apakah Anda yakin ingin keluar? (Y/N): ");
        startKata(); 
        if (compareKata(currentWord, "Y")) {
            quit = 'Y';
        } else {
            quit = 'N';
        }
    } else {
        printf("Perintah tidak valid! Silakan coba lagi.\n");
    }


        } else if (session == 3) {
            printf("\n=====[ Welcome to PURRMART ]=====\n");
            while (1) {
                mainMenu();
                startKata(); 

                if (compareKata(currentWord, "WORK")) {
                    printf("\n");
                    work(&saldo);
                } else if (compareKata(currentWord, "WORK CHALLENGE")) {
                    printf("Masukkan tantangan yang ingin dimainkan (1. Tebak Angka, 2. W0RDL3): ");
                    startKata(); 
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
                } else if (compareKata(currentWord, "STORE LIST")) {
                    printf("\n");
                    store_list(store);
                } else if (compareKata(currentWord, "STORE REQUEST")) {
                    printf("\n");
                    storeRequest(&requestQueue, store);
                } else if (compareKata(currentWord, "STORE SUPPLY")) {
                    printf("\n");
                    storeSupply(&requestQueue, &store);
                } else if (compareKata(currentWord, "STORE REMOVE")) {
                    printf("\n");
                    store_remove(&store);
                } else if (compareKata(currentWord, "HELP")) {
                    printf("\n");
                    show_main_menu_help();
                } else if (compareKata(currentWord, "LOGOUT")) {
                    printf("\n");
                    logout_user();
                    session = 2; 
                } else if (compareKata(currentWord, "SAVE")) {
                    printf("\n");
                    ADVKata();
                    wordToString(currentWord, filename);
                    SAVE_TO_FILE(barang, jumlahBarang, users, jumlahUsers, filename);
                } else if (compareKata(currentWord, "QUIT")) {
                    printf("Apakah Anda yakin ingin keluar? (Y/N): ");
                    startKata(); 
                    if (compareKata(currentWord, "Y")) {
                        quit = 'Y';
                    } else {
                        quit = 'N';
                    }
                    break; 
                } else {
                    printf("Perintah tidak valid! Silakan coba lagi.\n");
                }

                if (quit == 'Y') break;
            }
        }
    }

    printf("Terima kasih telah menggunakan PURRMART. Sampai jumpa!\n");
    return 0;
}
