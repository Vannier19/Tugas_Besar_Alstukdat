#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define MAX_ITEMS 100
#define MAX_USERS 50
#define MAX_STR 100
#define MAX_LEN 100
#define Mark -1

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
} User;

typedef struct {
  char name[MAX_LEN];
  int price; // harga barang
} Barang;

typedef struct {
    Barang A[MAX_ITEMS]; // Menyimpan array barang
    int Count;           // Jumlah barang yang ada
} List;

// ********** KONSTRUKTOR **********
void CreateList(List *L) {
    L->Count = 0;
}

// ********** TEST KOSONG / PENUH **********
boolean IsEmpty(List L) {
    return (L.Count == 0);
}

boolean IsFull(List L) {
    return (L.Count == MAX_ITEMS);
}

// ********** OPERASI DASAR **********
int Length(List L) {
    return L.Count;
}

Barang Get(List L, int idx) {
    return L.A[idx];
}

void Set(List *L, int idx, Barang B) {
    L->A[idx] = B;
}

// ********** SELEKTOR INDEKS **********
int IdxFirst(List L) {
    return IsEmpty(L) ? Mark : 0;
}

int IdxLast(List L) {
    return IsEmpty(L) ? Mark : L.Count - 1;
}

boolean IsIdxValid(int idx) {
    return (idx >= 0 && idx < MAX_ITEMS);
}

boolean IsIdxEff(List L, int idx) {
    return (idx >= 0 && idx < L.Count);
}

// ********** OPERASI PENAMBAHAN **********
void InsertFirst(List *L, Barang B) {
    if (!IsFull(*L)) {
        for (int i = L->Count; i > 0; i--) {
            L->A[i] = L->A[i - 1];
        }
        L->A[0] = B;
        L->Count++;
    }
}

void InsertLast(List *L, Barang B) {
    if (!IsFull(*L)) {
        L->A[L->Count] = B;
        L->Count++;
    }
}

void InsertAt(List *L, Barang B, int idx) {
    if (!IsFull(*L) && idx >= 0 && idx <= L->Count) {
        for (int i = L->Count; i > idx; i--) {
            L->A[i] = L->A[i - 1];
        }
        L->A[idx] = B;
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

int main() {
    List list;
    CreateList(&list);

    // Tambahkan beberapa barang untuk dihapus nanti
    Barang barang1 = {"Laptop", 15000};
    Barang barang2 = {"Mouse", 500};
    Barang barang3 = {"Keyboard", 750};
    
    // Insert barang ke dalam list
    InsertLast(&list, barang1);
    InsertLast(&list, barang2);
    InsertLast(&list, barang3);

    // Tampilkan isi list sebelum penghapusan
    printf("List barang sebelum penghapusan:\n");
    for (int i = 0; i < Length(list); i++) {
        printf("- %s\n", list.A[i].name);
    }

    // Panggil fungsi store_remove untuk menghapus barang
    store_remove(&list);

    // Tampilkan isi list setelah penghapusan
    printf("\nList barang setelah penghapusan:\n");
    for (int i = 0; i < Length(list); i++) {
        printf("- %s\n", list.A[i].name);
    }

    return 0;
}
