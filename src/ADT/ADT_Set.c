#include <stdio.h>
#include "ADT_Set.h"
/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S){
    S -> Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S){
    return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S){
    return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, infotype Elmt){
    if (!IsFull(*S)){
        if(!IsMember(*S, Elmt)){
            S -> Elements[S -> Count] = Elmt;
            S -> Count++;
        }
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSet(Set *S, infotype Elmt){
    if (!IsEmpty(*S)){
        int idx = -1;
        for (int i = 0; i <S->Count;i++){
            if(S->Elements[i] == Elmt){
                idx = i;
                break;
            }
        }
    if (idx != -1){
        for (int i = idx; i< S->Count-1; i++){
            S -> Elements[i] = S->Elements[i+1];
        }
        S -> Count--;
    }
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, infotype Elmt){
    for (int i = 0; i<S.Count; i++){
        if (S.Elements[i] == Elmt){
            return true;
        }
    }
    return false;
}
/* Mengembalikan true jika Elmt adalah member dari S */