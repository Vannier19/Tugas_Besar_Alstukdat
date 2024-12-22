#include <stdio.h>
#include <stdlib.h>
#include "ADT_Array_Dinamis.h"

#ifndef INT_MAX
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#endif

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
// void CreateListDin(ListDin *l, int capacity)
// /* I.S. l sembarang, capacity > 0 */
// /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
// {
//     BUFFER(*l) = NULL;
//     BUFFER(*l) = malloc(capacity * sizeof(ElType));
//     NEFF(*l) = 0;
//     CAPACITY(*l) = capacity;
//     // if(BUFFER(*l) == NULL){
//     //     printf("Error allocating memory.");
//     // }
//     // else{
//     //     printf("Success! Memory allocated.");
//     // }
// }

void CreateListDin(ListDin *barang, int capacity) {
    barang->buffer = (Barang *)malloc(capacity * sizeof(Barang));
    if (barang->buffer == NULL) {
        printf("Gagal mengalokasikan memori untuk ListDin.\n");
        exit(EXIT_FAILURE);
    }
    barang->capacity = capacity;
    barang->nEff = 0; // Awalnya, jumlah elemen efektif adalah 0
}



void dealocateList(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(BUFFER(*l));
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFF(l);
}
/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return NEFF(l) - 1;
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return i >= IDX_MIN && i < CAPACITY(l);
}

boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    return i >= getFirstIdx(l) && i <= getLastIdx(l);
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    return !NEFF(l);
}
/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return NEFF(l) == CAPACITY(l);
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    int i, n;
    do{
        scanf("%d", &n);
    } while(n < 0 || n > CAPACITY(*l));
    NEFF(*l) = n;
    for(i = 0;i<n;i++){
        scanf("%d", &ELMT(*l, i));
    }
}

void printList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    printf("[");
    int i, n = NEFF(l);
    if(n > 0){
        printf("%d", ELMT(l, 0));
    }
    for(i = 1; i<n; i++){
        printf(",%d", ELMT(l, i));
    }
    printf("]");
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */



/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
    int i, len = NEFF(lIn), cap = CAPACITY(lIn);
    CreateListDin(lOut, cap);
    for(i = 0;i<len;i++){
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = len;
    CAPACITY(*lOut) = cap;
}



/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l)++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    NEFF(*l)--;
    *val = ELMT(*l, NEFF(*l)); 
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    int cap = CAPACITY(*l);
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(int)*(cap+num));
    CAPACITY(*l)+=num;
}

void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    int cap = CAPACITY(*l);
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(int)*(cap-num));
    CAPACITY(*l)-=num;
}

void compressList(ListDin *l)
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    int n = NEFF(*l);
    // printf("n=%d\n", n);
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(int)*n);
    CAPACITY(*l) = n;
    // printf("sizeof buffer = %zu\n", sizeof(BUFFER(*l))/sizeof(int));
}

void deleteAtDin(ListDin *list, int idx) {
    if (isIdxEff(*list, idx)) {
        for (int i = idx; i < NEFF(*list) - 1; i++) {
            list->buffer[i] = list->buffer[i + 1];
        }
        NEFF(*list)--;
    }
}

// int main(){
//     ListDin l;
//     CreateListDin(&l, 10);
//     readList(&l);
//     sort(&l, false);
//     printList(l);
//     return 0;
// }