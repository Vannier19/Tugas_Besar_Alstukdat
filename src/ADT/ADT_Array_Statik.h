/* MODUL INTEGER STATIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* List ini digunakan untuk menyimpan list User*/
#ifndef LIST_H
#define LIST_H

#include "ADT_Kustom.h"
#include "ADT_Mesin_Kata.h"
#include "../boolean.h"

// Konstanta
#define Mark -1

// Struktur data list
typedef struct {
    User A[MAX_USERS]; // Array untuk menyimpan User
    int Count;         // Banyaknya elemen efektif dalam list
} List;

// ********** KONSTRUKTOR **********
void CreateListUser(List *L);
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan elemen efektif 0 */

// ********** TEST KOSONG / PENUH **********
boolean IsEmptyUser(List L);
/* Mengirimkan true jika list kosong */

boolean IsFullUser(List L);
/* Mengirimkan true jika list penuh */

// ********** OPERASI DASAR **********
int LengthUser(List L);
/* Mengirimkan jumlah elemen efektif dalam list */

User GetUser(List L, int idx);
/* Prekondisi: idx adalah indeks valid dalam list */
/* Mengembalikan elemen User pada indeks ke-idx */

void SetUser(List *L, int idx, User U);
/* Mengubah elemen User pada indeks ke-idx dengan U */

// ********** SELEKTOR INDEKS **********
int IdxFirstUser(List L);
/* Mengirimkan indeks elemen pertama (0 jika list tidak kosong) */

int IdxLastUser(List L);
/* Mengirimkan indeks elemen terakhir (Count - 1 jika list tidak kosong) */

boolean IsIdxValidUser(int idx);
/* Mengirimkan true jika idx berada dalam rentang indeks array [0..MAX_USERS-1] */

boolean IsIdxEffUser(List L, int idx);
/* Mengirimkan true jika idx adalah indeks efektif dalam list */

// ********** OPERASI PENAMBAHAN **********
void InsertFirstUser(List *L, User U);
/* Menambahkan elemen baru di awal list */

void InsertLastUser(List *L, User U);
/* Menambahkan elemen baru di akhir list */

void InsertAtUser(List *L, User U, int idx);
/* Menambahkan elemen baru di indeks ke-idx */

// ********** OPERASI PENGHAPUSAN **********
void DeleteFirstUser(List *L);
/* Menghapus elemen pertama dari list */

void DeleteLastUser(List *L);
/* Menghapus elemen terakhir dari list */

void DeleteAtUser(List *L, int idx);
/* Menghapus elemen pada indeks ke-idx */

// ********** OPERASI PENCARIAN **********
int SearchInListUser(List L, Word key);
/* Mencari elemen dalam list berdasarkan nama menggunakan Mesin Kata.
 * IS: List terdefinisi dan kata key terdefinisi.
 * FS: Mengembalikan indeks elemen pertama yang cocok dengan key, atau -1 jika tidak ditemukan.
 */

#endif