#ifndef Kustom
#define Kustom

#include "ADT_Stack.h"
#include "ADT_Map.h"
#include "ADT_List_Linier.h"


#define MAX_ITEMS 100
#define MAX_USERS 50
#define MAX_STR 100
#define MAX_LEN 100

// typedef struct Stack Stack;
// typedef struct {
//   char name[MAX_LEN];
//   int price;
// } Barang;

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
  Map keranjang;
  Stack riwayat_pembelian;
  ListLinier wishlist;
} User;

// int main() {
//   User ken;
//   ken.riwayat_pembelian.items->item.name;
//   return 0;
// }
// Stack ken;
// ken.
// typedef struct {
//   char name[MAX_LEN];
//   int harga;
// } Barang;

#endif