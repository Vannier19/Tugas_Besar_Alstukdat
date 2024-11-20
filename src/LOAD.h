#ifndef LOAD_H
#define LOAD_H
#include"mesinkata.h"
#include "ADT_Kustom.h"
extern int itemCount;
extern int userCount;
#define MAX_ITEMS 100
#define MAX_USERS 50
#define MAX_STR 100

Barang items[MAX_ITEMS];
User users[MAX_USERS];

int WordToInt(Word w);
void CopyWordToString(char *str, Word w);
int loadData(const char *filename);

#endif
