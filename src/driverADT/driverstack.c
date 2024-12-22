#include <stdio.h>
#include "../ADT/ADT_Stack.h"

int main() {
    Stack S;
    ItemStack X;

    CreateEmptyStack(&S);

    if (IsEmptyStack(S)) {
        printf("Stack kosong\n");
    }
    ItemStack item1 = {.item = "Barang1", .totalBiaya = 100};
    ItemStack item2 = {.item = "Barang2", .totalBiaya = 200};
    ItemStack item3 = {.item = "Barang3", .totalBiaya = 300};
    PushStack(&S, item1);
    PushStack(&S, item2);
    PushStack(&S, item3);

    printf("Panjang Stack %d\n", LengthStack(S));

    while (!IsEmptyStack(S)) {
        PopStack(&S, &X);
        printf("hasil pop stack %d\n", X);
    }

    if (IsEmptyStack(S)) {
        printf("Jika Stack kosong, ini di print\n");
    }
    else {
        printf("Jika Stack tidak kosong, ini di print\n");
    }

    return 0;
}