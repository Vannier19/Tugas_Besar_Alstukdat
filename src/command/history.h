#ifndef HISTORY_H
#define HISTORY_H

#include <stdio.h>
#include "../ADT/ADT_Stack.h"
#include "../ADT/ADT_Kustom.h"
#include "load.h"

/* Menampilkan riwayat pembelian barang dari stack riwayat pembelian */
void showHistory(Stack *S, int N);
/* I.S. Stack S terdefinisi */
/* F.S. Menampilkan N item terakhir dari riwayat pembelian */
/* Jika stack kosong, akan mencetak pesan bahwa riwayat kosong */

#endif
