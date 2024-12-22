#include <stdio.h>
#include <stdlib.h>
#include "ADT_List_Linier.h"

// Implementasi fungsi IsEmptyLinier
boolean IsEmptyLinier(ListLinier L) {
    return (First(L) == NilList);
}

// Membuat list kosong
void CreateEmptyLinier(ListLinier *L) {
    First(*L) = NilList;
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
addressList Alokasi(infotypeList X) {
    addressList P = (addressList)malloc(sizeof(ElmtList));
    if (P != NilList) {
        manual_strcpy(Info(P).TabWord, X.TabWord);  // Salin kata ke dalam info
        Info(P).Length = X.Length;  // Salin panjang kata
        Next(P) = NilList;
    }
    return P;
}

// Dealokasi elemen
void Dealokasi(addressList *P) {
    free(*P);
}

// Menambah elemen di awal list
void InsVFirst(ListLinier *L, infotypeList X) {
    addressList P = Alokasi(X);
    if (P != NilList) {
        InsertFirst(L, P);
    }
}

// Menambah elemen di akhir list
void InsVLast(ListLinier *L, infotypeList X) {
    addressList P = Alokasi(X);
    if (P != NilList) {
        InsertLast(L, P);
    }
}

// Menampilkan isi list
void PrintInfo(ListLinier L) {
    addressList P;
    boolean isFirst = true;

    printf("[");
    if (!IsEmptyLinier(L)) {
        P = First(L);
        while (P != NilList) {
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
void InsertFirst(ListLinier *L, addressList P) {
    Next(P) = First(*L);
    First(*L) = P;
}

// Menambahkan elemen di akhir list
void InsertLast(ListLinier *L, addressList P) {
    if (IsEmptyLinier(*L)) {
        InsertFirst(L, P);
    } else {
        addressList last = First(*L);
        while (Next(last) != NilList) {
            last = Next(last);
        }
        Next(last) = P;
    }
}

void InsertAfter (ListLinier *L, addressList P, addressList Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

// Menghapus elemen pertama
void DelVFirst(ListLinier *L, infotypeList *X) {
    addressList P = First(*L);
    if (P != NilList) {
        manual_strcpy(X->TabWord, Info(P).TabWord);
        X->Length = Info(P).Length;
        First(*L) = Next(P);
        Dealokasi(&P);
    }
}

// Menghapus elemen terakhir
void DelVLast(ListLinier *L, infotypeList *X) {
    if (IsEmptyLinier(*L)) {
        return;
    }
    
    addressList P = First(*L);
    addressList Prec = NilList;
    while (Next(P) != NilList) {
        Prec = P;
        P = Next(P);
    }
    
    if (Prec != NilList) {
        Next(Prec) = NilList;
    } else {
        First(*L) = NilList;
    }
    
    manual_strcpy(X->TabWord, Info(P).TabWord);
    X->Length = Info(P).Length;
    Dealokasi(&P);
}



// Fungsi untuk mencari apakah elemen ada dalam list
boolean Search(ListLinier L, infotypeList X) {
    addressList P = First(L);
    while (P != NilList) {
        if (manual_strcmp(Info(P).TabWord, X.TabWord) == 0) {
            return true;
        }
        P = Next(P);
    }
    return false;
}

// Menghitung jumlah elemen dalam list
int NbElmt(ListLinier L) {
    int count = 0;
    addressList P = First(L);
    while (P != NilList) {
        count++;
        P = Next(P);
    }
    return count;
}

// Fungsi untuk mendapatkan nama barang maksimum (secara lexicographical)
infotypeList Max(ListLinier L) {
    addressList P = First(L);
    infotypeList max;
    manual_strcpy(max.TabWord, Info(P).TabWord);
    max.Length = Info(P).Length;
    P = Next(P);
    while (P != NilList) {
        if (manual_strcmp(Info(P).TabWord, max.TabWord) > 0) {
            manual_strcpy(max.TabWord, Info(P).TabWord);
            max.Length = Info(P).Length;
        }
        P = Next(P);
    }
    return max;
}

// Fungsi untuk mendapatkan kata minimum (secara lexicographical)
infotypeList Min(ListLinier L) {
    addressList P = First(L);
    infotypeList min;
    manual_strcpy(min.TabWord, Info(P).TabWord);
    min.Length = Info(P).Length;
    P = Next(P);
    while (P != NilList) {
        if (manual_strcmp(Info(P).TabWord, min.TabWord) < 0) {
            manual_strcpy(min.TabWord, Info(P).TabWord);
            min.Length = Info(P).Length;
        }
        P = Next(P);
    }
    return min;
}

void DelAfter (ListLinier *L, addressList *Pdel, addressList Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = NilList;
}
/* I.S. ListLinier tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void DelAt (ListLinier *L, addressList Pdel, infotypeList *X){
    addressList P = First(*L);
    
    while (Next(P) != Pdel && P != NilList){
        P = Next(P);
    }
    if (P != NilList){
        Next(P) = Next(Pdel);
        manual_strcpy(X->TabWord, Info(Pdel).TabWord);
        X->Length = Info(Pdel).Length;
        Dealokasi(&Pdel);
    }
}

void swabElmt(addressList P1, addressList P2){
    infotypeList temp;
    manual_strcpy(temp.TabWord, Info(P1).TabWord);
    temp.Length = Info(P1).Length;
    manual_strcpy(Info(P1).TabWord, Info(P2).TabWord);
    Info(P1).Length = Info(P2).Length;
    manual_strcpy(Info(P2).TabWord, temp.TabWord);
    Info(P2).Length = temp.Length;
}


void Swap_Indeks(ListLinier *L, int idx1, int idx2){
    addressList P1 = First(*L);
    addressList P2 = First(*L);
    for(int i = 1; i < idx1; i++){
        P1 = Next(P1);
    }
    for(int i = 1; i < idx2; i++){
        P2 = Next(P2);
    }
    swabElmt(P1, P2);
}
/* I.S. ListLinier tidak kosong */
/* F.S. Info(P1) dan Info(P2) ditukar */