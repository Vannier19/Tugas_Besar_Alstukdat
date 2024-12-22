#include <stdio.h>
#include "../ADT/ADT_List_Linier.h"

int main() {
    ListLinier L;
    infotypeList X;
    addressList P;

    CreateEmptyLinier(&L);
    printf("List created. Is empty: %d\n", IsEmptyLinier(L));

    X.Length = 5;
    manual_strcpy(X.TabWord, "apple");
    InsVFirst(&L, X);
    PrintInfo(L);
    printf("\n");

    X.Length = 6;
    manual_strcpy(X.TabWord, "banana");
    InsVLast(&L, X);
    PrintInfo(L);
    printf("\n");

    X.Length = 4;
    manual_strcpy(X.TabWord, "gojo");
    InsVFirst(&L, X);
    PrintInfo(L);
    printf("\n");

    printf("Jumlah elemen %d\n", NbElmt(L));

    X.Length = 6;
    manual_strcpy(X.TabWord, "banana");
    printf("Search banana %d\n", Search(L, X));

    printf("Max element: %s\n", Max(L).TabWord);
    printf("Min element: %s\n", Min(L).TabWord);

    DelVFirst(&L, &X);
    printf("Delete first element '%s'.", X.TabWord);
    PrintInfo(L);
    printf("\n");

    DelVLast(&L, &X);
    printf("Delete last element '%s'.", X.TabWord);
    PrintInfo(L);
    printf("\n");

    X.Length = 5;
    manual_strcpy(X.TabWord, "grape");
    InsVLast(&L, X);
    printf("Insert last.");
    PrintInfo(L);
    printf("\n");

    X.Length = 6;
    manual_strcpy(X.TabWord, "orange");
    InsVLast(&L, X);
    printf("Insert last.");
    PrintInfo(L);
    printf("\n");

    Swap_Indeks(&L, 1, 2);
    printf("Swap elemen ke 1 and 2.");
    PrintInfo(L);
    printf("\n");

    return 0;
}