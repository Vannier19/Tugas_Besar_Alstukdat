#include <stdio.h>
#include <stdlib.h>
#include "store_remove.h"

void store_remove(List *list) {
    char nama_barang_dihapus[MAX_STR];
    printf("Nama barang yang akan dihapus: ");
    scanf("%s", nama_barang_dihapus);

    int indeks = -1;

    for (int i = 0; i < list->Count; i++){
        int j = 0;
        boolean sama = true;
        while (nama_barang_dihapus[j] != '\0' || list->A[i].name[j] != '\0') {
            if (nama_barang_dihapus[j] != list->A[i].name[j]) {
                sama = false;
                break;
            }
            j++;
        }

        if (sama) {
            indeks = i;
            break;
        }
    }

    if (IsIdxEff(*list, indeks)) {
        DeleteAt(list, indeks);
        printf("%s telah berhasil dihapus.\n", nama_barang_dihapus);
    } else {
        printf("Toko tidak menjual %s\n", nama_barang_dihapus);
    }
}
