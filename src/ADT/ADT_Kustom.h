#ifndef LISTDIN_H
#define LISTDIN_H

#include "boolean.h"
#define MAX_ITEMS 100
#define MAX_USERS 50
#define MAX_STR 100
#define MAX_LEN 10000000
typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
} User;


typedef struct {
  char name[MAX_LEN];
  int price;
} Barang;
#endif