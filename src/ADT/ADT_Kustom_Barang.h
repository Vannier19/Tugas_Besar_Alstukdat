#ifndef BARANG_H
#define BARANG_H

#define MAX_ITEMS 100
#define MAX_USERS 50
#define MAX_STR 100
#define MAX_LEN 100

typedef struct {
  char name[MAX_LEN];
  int price;
} Barang;

#endif