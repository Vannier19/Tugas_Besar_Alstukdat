#include <stdio.h>
#include "ADT_Stack.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 0.. MaxElStack */
/* Ciri stack kosong : TOP bernilai Undef */
{
    Top(*S) = Undef;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S)==Undef);
}

boolean IsFullStack (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S)==MaxElStack-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack (Stack * S, ItemStack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S) += 1;
    S->items[S->TOP] = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack (Stack * S, ItemStack* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = S->items[S->TOP];
    Top(*S) -= 1;
}

int LengthStack(Stack S) {
    int length = 0;
    address idx = Top(S);

    while (idx != Undef) {
        length++;
        idx--;
    }

    return length;
}

void ClearStack(Stack *S) {
    ItemStack trash;
    while (Top(*S) != Undef) {
        PopStack(S, &trash);
    }
}

void AddToHistory(Stack *history, Stack *cart) {
    int i = Top(*history);

    // Cari posisi yang benar berdasarkan nama barang secara leksikografis
    while (i >= 0 && compareStrings(history->items[i].item.name, cart->items[0].item.name) < 0) {
        // Geser elemen ke atas untuk memberi ruang
        history->items[i + 1] = history->items[i];
        i--;
    }

    // Masukkan elemen baru ke posisi yang benar
    history->items[i + 1] = cart->items[0]; // Asumsikan hanya satu barang dari cart yang ditambahkan
    Top(*history) += 1;
}
