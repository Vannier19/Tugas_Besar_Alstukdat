/* MODUL INTEGER STATIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* List ini digunakan untuk menyimpan list User*/
#ifndef LIST_H
#define LIST_H

#include "ADT_Kustom.h"
#include "../boolean.h"

// Konstanta
#define Mark -1

// Struktur data list
typedef struct {
    User A[MAX_USERS]; // Array untuk menyimpan User
    int Count;         // Banyaknya elemen efektif dalam list
} List;

// ********** KONSTRUKTOR **********
void CreateList(List *L);
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan elemen efektif 0 */

// ********** TEST KOSONG / PENUH **********
boolean IsEmpty(List L);
/* Mengirimkan true jika list kosong */

boolean IsFull(List L);
/* Mengirimkan true jika list penuh */

// ********** OPERASI DASAR **********
int Length(List L);
/* Mengirimkan jumlah elemen efektif dalam list */

User Get(List L, int idx);
/* Prekondisi: idx adalah indeks valid dalam list */
/* Mengembalikan elemen User pada indeks ke-idx */

void Set(List *L, int idx, User U);
/* Mengubah elemen User pada indeks ke-idx dengan U */

// ********** SELEKTOR INDEKS **********
int IdxFirst(List L);
/* Mengirimkan indeks elemen pertama (0 jika list tidak kosong) */

int IdxLast(List L);
/* Mengirimkan indeks elemen terakhir (Count - 1 jika list tidak kosong) */

boolean IsIdxValid(int idx);
/* Mengirimkan true jika idx berada dalam rentang indeks array [0..MAX_USERS-1] */

boolean IsIdxEff(List L, int idx);
/* Mengirimkan true jika idx adalah indeks efektif dalam list */

// ********** OPERASI PENAMBAHAN **********
void InsertFirst(List *L, User U);
/* Menambahkan elemen baru di awal list */

void InsertLast(List *L, User U);
/* Menambahkan elemen baru di akhir list */

void InsertAt(List *L, User U, int idx);
/* Menambahkan elemen baru di indeks ke-idx */

// ********** OPERASI PENGHAPUSAN **********
void DeleteFirst(List *L);
/* Menghapus elemen pertama dari list */

void DeleteLast(List *L);
/* Menghapus elemen terakhir dari list */

void DeleteAt(List *L, int idx);
/* Menghapus elemen pada indeks ke-idx */

#endif
