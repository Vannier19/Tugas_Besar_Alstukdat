#include <stdio.h>
#include "ADT_Array_Dinamis.h"

int main() {
    ListDin l;
    Barang val;

    CreateListDin(&l, 5);

    val.price = 100;
    val.name[0] = 'A';
    val.name[1] = 'l';
    val.name[2] = 'i';
    val.name[3] = '\0';
    insertLast(&l, val);

    val.price = 200;
    val.name[0] = 'B';
    val.name[1] = 'o';
    val.name[2] = 'b';
    val.name[3] = '\0';
    insertLast(&l, val);

    val.price = 300;
    val.name[0] = 'C';
    val.name[1] = 'a';
    val.name[2] = 'r';
    val.name[3] = 'l';
    val.name[4] = 'o';
    val.name[5] = 's';
    val.name[6] = '\0';
    insertLast(&l, val);

    printf("Isi list setelah penambahan elemen: ");
    printList(l);
    printf("\n");

    deleteLast(&l, &val);
    printf("Elemen yang dihapus: %s, %d\n", val.name, val.price);

    printf("Isi list setelah penghapusan elemen terakhir: ");
    printList(l);
    printf("\n");

    return 0;
}
