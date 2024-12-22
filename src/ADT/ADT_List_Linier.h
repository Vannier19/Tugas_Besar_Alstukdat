#ifndef listlinier_H
#define listlinier_H

#include <stdlib.h>
#include <stdio.h>
#include "../boolean.h"
#include "ADT_Mesin_Kata.h"

#define NilList NULL
#define Kata Word
// Mengubah infotypeList menjadi string
typedef Kata infotypeList; 
typedef struct tElmtlist *addressList;
typedef struct tElmtlist { 
    infotypeList info;
    addressList next;
} ElmtList;
typedef struct {
    addressList First;
} ListLinier;

/* Definisi list : */
/* ListLinier kosong : First(L) = NilList */
/* Setiap elemen dengan addressList P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=NilList */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Last(L) ((L).Last)

void manual_strcpy(char *dest, const char *src);
int manual_strcmp(const char *str1, const char *str2);

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLinier (ListLinier L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLinier (ListLinier *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressList Alokasi (infotypeList X);
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=NilList */
/* Jika alokasi gagal, mengirimkan NilList */
void Dealokasi (addressList *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListLinier *L, infotypeList X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (ListLinier *L, infotypeList X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListLinier *L, infotypeList *X);
/* I.S. ListLinier L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (ListLinier *L, infotypeList *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListLinier *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
void InsertAfter (ListLinier *L, addressList P, addressList Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (ListLinier *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListLinier *L, addressList *P);
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (ListLinier *L, infotypeList X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* ListLinier mungkin menjadi kosong karena penghapusan */
void DelLast (ListLinier *L, addressList *P);
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (ListLinier *L, addressList *Pdel, addressList Prec);
/* I.S. ListLinier tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void DelAt (ListLinier *L, addressList Pdel, infotypeList *X);
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (ListLinier L);
/* I.S. ListLinier mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
int NbElmt (ListLinier L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

boolean Search(ListLinier L, infotypeList X);
void swabElmt(addressList P1, addressList P2);
/* I.S. P1 dan P2 adalah addressList dari elemen list */
/* F.S. Info(P1) dan Info(P2) ditukar */



/*** Prekondisi untuk Max/Min/rata-rata : ListLinier tidak kosong ***/
infotypeList Max (ListLinier L);
/* Mengirimkan nilai info(P) yang maksimum */
addressList AdrMax (ListLinier L);
/* Mengirimkan addressList P, dengan info(P) yang bernilai maksimum */
infotypeList Min (ListLinier L);
/* Mengirimkan nilai info(P) yang minimum */
addressList AdrMin (ListLinier L);
/* Mengirimkan addressList P, dengan info(P) yang bernilai minimum */
float Average (ListLinier L);
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (ListLinier *L);
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (ListLinier *L1, ListLinier *L2, ListLinier *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void swapElmt(addressList P1, addressList P2);
/* I.S. P1 dan P2 adalah addressList dari elemen list */
/* F.S. Info(P1) dan Info(P2) ditukar */

void Swap_Indeks(ListLinier *L, int idx1, int idx2);
/* I.S. ListLinier tidak kosong */
/* F.S. Info(P1) dan Info(P2) ditukar */

#endif