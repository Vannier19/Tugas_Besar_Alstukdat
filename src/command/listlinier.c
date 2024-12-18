#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

// Implementasi fungsi IsEmptyLinier
boolean IsEmptyLinier(List L) {
    return (First(L) == Nil);
}

// Membuat list kosong
void CreateEmptyLinier(List *L) {
    First(*L) = Nil;
}
// Implementasi manual dari strcpy
void manual_strcpy(char *dest, const char *src) {
    while ((*dest++ = *src++) != '\0');
}

// Implementasi manual untuk strcmp pada Word
int manual_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

// Alokasi elemen baru
address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        manual_strcpy(Info(P).TabWord, X.TabWord);  // Salin kata ke dalam info
        Info(P).Length = X.Length;  // Salin panjang kata
        Next(P) = Nil;
    }
    return P;
}

// Dealokasi elemen
void Dealokasi(address *P) {
    free(*P);
}

// Menambah elemen di awal list
void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
}

// Menambah elemen di akhir list
void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L, P);
    }
}

// Menampilkan isi list
void PrintInfo(List L) {
    address P;
    boolean isFirst = true;

    printf("[");
    if (!IsEmptyLinier(L)) {
        P = First(L);
        while (P != Nil) {
            if (!isFirst) {
                printf(",");
            }
            printf("%s", Info(P).TabWord); 
            isFirst = false;
            P = Next(P);
        }
    }
    printf("]");
}

// Menambahkan elemen di awal list
void InsertFirst(List *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}

// Menambahkan elemen di akhir list
void InsertLast(List *L, address P) {
    if (IsEmptyLinier(*L)) {
        InsertFirst(L, P);
    } else {
        address last = First(*L);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        Next(last) = P;
    }
}

void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

// Menghapus elemen pertama
void DelVFirst(List *L, infotype *X) {
    address P = First(*L);
    if (P != Nil) {
        manual_strcpy(X->TabWord, Info(P).TabWord);
        X->Length = Info(P).Length;
        First(*L) = Next(P);
        Dealokasi(&P);
    }
}

// Menghapus elemen terakhir
void DelVLast(List *L, infotype *X) {
    if (IsEmptyLinier(*L)) {
        return;
    }
    
    address P = First(*L);
    address Prec = Nil;
    while (Next(P) != Nil) {
        Prec = P;
        P = Next(P);
    }
    
    if (Prec != Nil) {
        Next(Prec) = Nil;
    } else {
        First(*L) = Nil;
    }
    
    manual_strcpy(X->TabWord, Info(P).TabWord);
    X->Length = Info(P).Length;
    Dealokasi(&P);
}



// Fungsi untuk mencari apakah elemen ada dalam list
boolean Search(List L, infotype X) {
    address P = First(L);
    while (P != Nil) {
        if (manual_strcmp(Info(P).TabWord, X.TabWord) == 0) {
            return true;
        }
        P = Next(P);
    }
    return false;
}

// Menghitung jumlah elemen dalam list
int NbElmt(List L) {
    int count = 0;
    address P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

// Fungsi untuk mendapatkan nama barang maksimum (secara lexicographical)
infotype Max(List L) {
    address P = First(L);
    infotype max;
    manual_strcpy(max.TabWord, Info(P).TabWord);
    max.Length = Info(P).Length;
    P = Next(P);
    while (P != Nil) {
        if (manual_strcmp(Info(P).TabWord, max.TabWord) > 0) {
            manual_strcpy(max.TabWord, Info(P).TabWord);
            max.Length = Info(P).Length;
        }
        P = Next(P);
    }
    return max;
}

// Fungsi untuk mendapatkan kata minimum (secara lexicographical)
infotype Min(List L) {
    address P = First(L);
    infotype min;
    manual_strcpy(min.TabWord, Info(P).TabWord);
    min.Length = Info(P).Length;
    P = Next(P);
    while (P != Nil) {
        if (manual_strcmp(Info(P).TabWord, min.TabWord) < 0) {
            manual_strcpy(min.TabWord, Info(P).TabWord);
            min.Length = Info(P).Length;
        }
        P = Next(P);
    }
    return min;
}

void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void DelAt (List *L, address Pdel, infotype *X){
    address P = First(*L);
    
    while (Next(P) != Pdel && P != Nil){
        P = Next(P);
    }
    if (P != Nil){
        Next(P) = Next(Pdel);
        manual_strcpy(X->TabWord, Info(Pdel).TabWord);
        X->Length = Info(Pdel).Length;
        Dealokasi(&Pdel);
    }
}

void swabElmt(address P1, address P2){
    infotype temp;
    manual_strcpy(temp.TabWord, Info(P1).TabWord);
    temp.Length = Info(P1).Length;
    manual_strcpy(Info(P1).TabWord, Info(P2).TabWord);
    Info(P1).Length = Info(P2).Length;
    manual_strcpy(Info(P2).TabWord, temp.TabWord);
    Info(P2).Length = temp.Length;
}


void Swap_Indeks(List *L, int idx1, int idx2){
    address P1 = First(*L);
    address P2 = First(*L);
    for(int i = 0; i < idx1; i++){
        P1 = Next(P1);
    }
    for(int i = 0; i < idx2; i++){
        P2 = Next(P2);
    }
    swabElmt(P1, P2);
}
/* I.S. List tidak kosong */
/* F.S. Info(P1) dan Info(P2) ditukar */

