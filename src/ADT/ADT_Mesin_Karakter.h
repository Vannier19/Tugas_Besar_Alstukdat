/* File: ADT_Mesin_Karakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../boolean.h"


#define MARK ';'
#define ENTER "\n"

/* State Mesin */
extern char currentChar;
extern boolean EOP;

void start();
/* Mesin siap dioperasikan dan pita disiapkan untuk dibaca.
   Karakter pertama merupakan karakter yang berada di jendela.
   Pita akan direset sebelum pembacaan dari stdin.
   I.S. : sembarang
   F.S. : currenChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP maka fungsi akan mengembalikan false
          Jika currentChar = MARK maka EOP maka fungsi akan mengembalikan true */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar yang baru adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan bernilai true */

void startFile(char *file_name);
/* Menyiapkan file untuk dibuka dan dibaca 
   I.S. : sembarang
   F.S. : Jika file berhasil dibuka maka success menjadi true
          Jika file tidak ditemukan atau aksesnya ditolak maka success menjadi false */
/* Mesin siap dioperasikan dan pita disiapkan untuk dibaca.
   Pita yang akan dibaca berada di dalam file dengan path ../data/file_name.
   Pita yang dibaca diambil dari fopen(path).
   I.S. : sembarang
   F.S. : currenChar adalah karakter pertama pada pita
         Jika currentChar != MARK maka EOP maka fungsi akan mengembalikan false
         Jika currentChar = MARK maka EOP maka fungsi akan mengembalikan true */

void ADVFile();

char getCC();
/* Mengirimkan currentChar */

boolean isEOP();
/* Mengirimkan true jika currentChar = MARK */

#endif