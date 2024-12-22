#include <stdio.h>
#include "ADT_Array_Statik.h"

// ********** KONSTRUKTOR **********
void CreateListUser(List *L) {
    L->Count = 0;
}

// ********** TEST KOSONG / PENUH **********
boolean IsEmptyUser(List L) {
    return (L.Count == 0);
}

boolean IsFullUser(List L) {
    return (L.Count == MAX_USERS);
}

// ********** OPERASI DASAR **********
int LengthUser(List L) {
    return L.Count;
}

User GetUser(List L, int idx) {
    return L.A[idx];
}

void SetUser(List *L, int idx, User U) {
    L->A[idx] = U;
}

// ********** SELEKTOR INDEKS **********
int IdxFirstUser(List L) {
    return IsEmptyUser(L) ? Mark : 0;
}

int IdxLastUser(List L) {
    return IsEmptyUser(L) ? Mark : L.Count - 1;
}

boolean IsIdxValidUser(int idx) {
    return (idx >= 0 && idx < MAX_USERS);
}

boolean IsIdxEffUser(List L, int idx) {
    return (idx >= 0 && idx < L.Count);
}

// ********** OPERASI PENAMBAHAN **********
void InsertFirstUser(List *L, User U) {
    if (!IsFullUser(*L)) {
        for (int i = L->Count; i > 0; i--) {
            L->A[i] = L->A[i - 1];
        }
        L->A[0] = U;
        L->Count++;
    }
}

void InsertLastUser(List *L, User U) {
    if (!IsFullUser(*L)) {
        L->A[L->Count] = U;
        L->Count++;
    }
}

void InsertAtUser(List *L, User U, int idx) {
    if (!IsFullUser(*L) && idx >= 0 && idx <= L->Count) {
        for (int i = L->Count; i > idx; i--) {
            L->A[i] = L->A[i - 1];
        }
        L->A[idx] = U;
        L->Count++;
    }
}

// ********** OPERASI PENGHAPUSAN **********
void DeleteFirstUser(List *L) {
    if (!IsEmptyUser(*L)) {
        for (int i = 0; i < L->Count - 1; i++) {
            L->A[i] = L->A[i + 1];
        }
        L->Count--;
    }
}

void DeleteLastUser(List *L) {
    if (!IsEmptyUser(*L)) {
        L->Count--;
    }
}

void DeleteAtUser(List *L, int idx) {
    if (!IsEmptyUser(*L) && idx >= 0 && idx < L->Count) {
        for (int i = idx; i < L->Count - 1; i++) {
            L->A[i] = L->A[i + 1];
        }
        L->Count--;
    }
}

// ********** OPERASI PENCARIAN **********
int SearchInListUser(List L, Word key) {
    for (int i = 0; i < L.Count; i++) {

        if (isEqualChar(L.A[i].name, key.TabWord)) {
            return i;
        }
    }
    return -1;
}