#ifndef SAVE_H
#define SAVE_H

#include <stdio.h>
#include "ADT_Kustom.h"

#define MAX_ITEMS 100
#define MAX_USERS 50
#define MAX_LEN 100

void SAVE_TO_FILE(Barang barang[], int jumlahBarang, User users[], int jumlahUsers, char *namaFile);

#endif // SAVE_H
