#ifndef LOAD_H
#define LOAD_H

#include "../boolean.h"
#include "../ADT/ADT_Kustom.h"
#include "../ADT/ADT_Stack.h"
#include "../ADT/ADT_Mesin_Kata.h"
#include "../ADT/ADT_List_Linier.h"
#include "../ADT/ADT_Array_Dinamis.h"
#include "../ADT/ADT_Array_Statik.h"

// boolean START_READ_FILE(char *filename, ListDin *barang, List *users);
boolean LOAD_Barang(char *filename, ListDin *barang);
boolean LOAD_User(char *filename, List *users);
boolean LOAD_History(char *filename, User users[], int jumlahUser, Stack *history);
boolean LOAD_Wishlist(char *filename, User users[], int jumlahUser, ListLinier *wishlist);
boolean LOAD(char *filename, ListDin *barang, List *users, Stack *history, ListLinier *wishlist);

#endif