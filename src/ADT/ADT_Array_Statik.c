
#include <stdio.h>
#include "ADT_Array_Statik.h"

// ********** KONSTRUKTOR **********
void CreateList(List *L) {
    L->Count = 0;
}

// ********** TEST KOSONG / PENUH **********
boolean IsEmpty(List L) {
    return (L.Count == 0);
}

boolean IsFull(List L) {
    return (L.Count == MAX_USERS);
}

// ********** OPERASI DASAR **********
int Length(List L) {
    return L.Count;
}

User Get(List L, int idx) {
    return L.A[idx];
}

void Set(List *L, int idx, User U) {
    L->A[idx] = U;
}

// ********** SELEKTOR INDEKS **********
int IdxFirst(List L) {
    return IsEmpty(L) ? Mark : 0;
}

int IdxLast(List L) {
    return IsEmpty(L) ? Mark : L.Count - 1;
}

boolean IsIdxValid(int idx) {
    return (idx >= 0 && idx < MAX_USERS);
}

boolean IsIdxEff(List L, int idx) {
    return (idx >= 0 && idx < L.Count);
}

// ********** OPERASI PENAMBAHAN **********
void InsertFirst(List *L, User U) {
    if (!IsFull(*L)) {
        for (int i = L->Count; i > 0; i--) {
            L->A[i] = L->A[i - 1];
        }
        L->A[0] = U;
        L->Count++;
    }
}

void InsertLast(List *L, User U) {
    if (!IsFull(*L)) {
        L->A[L->Count] = U;
        L->Count++;
    }
}

void InsertAt(List *L, User U, int idx) {
    if (!IsFull(*L) && idx >= 0 && idx <= L->Count) {
        for (int i = L->Count; i > idx; i--) {
            L->A[i] = L->A[i - 1];
        }
        L->A[idx] = U;
        L->Count++;
    }
}

// ********** OPERASI PENGHAPUSAN **********
void DeleteFirst(List *L) {
    if (!IsEmpty(*L)) {
        for (int i = 0; i < L->Count - 1; i++) {
            L->A[i] = L->A[i + 1];
        }
        L->Count--;
    }
}

void DeleteLast(List *L) {
    if (!IsEmpty(*L)) {
        L->Count--;
    }
}

void DeleteAt(List *L, int idx) {
    if (!IsEmpty(*L) && idx >= 0 && idx < L->Count) {
        for (int i = idx; i < L->Count - 1; i++) {
            L->A[i] = L->A[i + 1];
        }
        L->Count--;
    }
}
