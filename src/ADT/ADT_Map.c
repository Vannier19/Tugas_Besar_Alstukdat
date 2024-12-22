#include <stdio.h>
// #include <string.h>
#include "ADT_Map.h"

void CreateEmptyMap(Map *M) {
    M->Count = 0;
}

boolean IsEmptyMap(Map M) {
    return (M.Count == 0);
}

boolean IsFullMap(Map M) {
    return (M.Count == MaxEl);
}

int ValueMap(Map M, Barang B) {
    int i;
    for (i = 0; i < M.Count; i++) {
        if (compareKata(currentWord, M.Elmt[i].Item.name)) {
            return M.Elmt[i].Total;
        }
    }
    return Undefined;
}

void InsertMap(Map *M, Barang B, int x) {
    if (!IsFullMap(*M)) {
        int i = M->Count;
        wordToString(currentWord, M->Elmt[i].Item.name);
        M->Elmt[i].Item.price = B.price;
        M->Elmt[i].Total = x;
        M->Elmt[i].Kuantitas = 1;
        M->Count++;
    }
}

void DeleteMap(Map *M, Barang B) {
    int i, pos = -1;
    for (i = 0; i < M->Count; i++) {
        if (compareKata(currentWord, M->Elmt[i].Item.name)) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        for (i = pos; i < M->Count - 1; i++) {
            M->Elmt[i] = M->Elmt[i + 1];
        }
        M->Count--;
    }
}

boolean IsMemberMap(Map M, Barang B) {
    int i;
    for (i = 0; i < M.Count; i++) {
        if (compareKata(currentWord, M.Elmt[i].Item.name)) {
            return true;
        }
    }
    return false;
}

void PrintMap(Map M) {
    int i;
    for (i = 0; i < M.Count; i++) {
        printf("Nama Barang: %s\n", M.Elmt[i].Item.name);
        printf("price Barang: %d\n", M.Elmt[i].Item.price);
        printf("Total: %d\n", M.Elmt[i].Total);
        printf("Kuantitas: %d\n", M.Elmt[i].Kuantitas);
        printf("----------------------\n");
    }
}

void findMap(Map M, int x, Barang *B) {
    int i;
    for (i = 0; i < M.Count; i++) {
        if (M.Elmt[i].Total == x) {
            wordToString(currentWord, B->name);
            B->price = M.Elmt[i].Item.price;
            return;
        }
    }
    B->name[0] = '\0';
    B->price = 0;
}