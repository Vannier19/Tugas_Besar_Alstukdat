#ifndef MAP_H
#define MAP_H
#include <stdio.h>
#include "../boolean.h"
#include "ADT_Kustom_Barang.h"
#include "ADT_Kustom_Barang.h"
#include "ADT_Mesin_Kata.h"

#define Nil 0
#define MaxEl 101
#define Undefined -999

typedef struct{
    Barang Item;
    int Total;
    int Kuantitas;
} Keranjang;

typedef struct{
    Keranjang Elmt[MaxEl];
    int Count;
} Map;

/* Prototype Fungsi Map */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M);
/* Membuat Map M kosong */

/* *** Predikat Untuk test keadaan Koleksi *** */
boolean IsEmptyMap(Map M);
/* Mengirim true jika Map M kosong */

boolean IsFullMap(Map M);
/* Mengirim true jika Map M penuh */

/* *** Operator Dasar Map *** */
int ValueMap(Map M, Barang B);
/* Mengembalikan value untuk key k, atau Undefined jika k tidak ada */

void InsertMap(Map *M, Barang B, int x);
/* Menambahkan elemen dengan key k dan value v ke dalam Map M */

void DeleteMap(Map *M, Barang B);
/* Menghapus elemen dengan key k dari Map M */

boolean IsMemberMap(Map M, Barang B);
/* Mengembalikan true jika k adalah anggota Map M */

void PrintMap(Map M);
/* Mencetak semua pasangan key-value dalam Map M */

void findMap(Map M, int x, Barang *B);
/* Mencari key untuk nilai tertentu v */

#endif