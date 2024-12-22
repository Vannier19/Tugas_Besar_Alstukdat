#ifndef SAVE_H
#define SAVE_H

#include "../ADT/ADT_Kustom.h"
#include "../ADT/ADT_Array_Dinamis.h"
#include "../ADT/ADT_Array_Statik.h"

// Fungsi untuk menyimpan data ke file
// Fungsi untuk menyimpan data ke file
void saveBarang(ListDin listBarang, const char *filename);
void saveUsers(List users, const char *filename);
void save(ListDin listBarang, List users, const char *filename);

#endif