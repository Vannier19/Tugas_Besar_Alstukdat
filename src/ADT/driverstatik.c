#include <stdio.h>
#include "ADT_Array_Statik.h"

int main() {
    List L;
    User user;
    Word word;
    
    CreateList(&L);

    user.money = 1000;
    user.name[0] = 'A';
    user.name[1] = 'l';
    user.name[2] = 'i';
    user.name[3] = '\0';
    InsertLast(&L, user);

    user.money = 2000;
    user.name[0] = 'B';
    user.name[1] = 'o';
    user.name[2] = 'b';
    user.name[3] = '\0';
    InsertLast(&L, user);

    printf("Panjang list: %d\n", Length(L));

    printf("Isi list:\n");
    for (int i = 0; i < Length(L); i++) {
        printf("User %d: %s, %d\n", i + 1, L.A[i].name, L.A[i].money);
    }

    word.Length = 3;
    word.TabWord[0] = 'A';
    word.TabWord[1] = 'l';
    word.TabWord[2] = 'i';
    word.TabWord[3] = '\0';

    int idx = SearchInList(L, word);
    if (idx != -1) {
        printf("User ditemukan pada indeks %d: %s, %d\n", idx, L.A[idx].name, L.A[idx].money);
    } else {
        printf("User tidak ditemukan.\n");
    }

    DeleteFirst(&L);
    printf("Setelah menghapus user pertama, panjang list: %d\n", Length(L));

    return 0;
}
