/* File: ADT_Mesin_Kata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "ADT_Mesin_Karakter.h"


#define NMax 150
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void resetCurrentKata();
/* Mengembalikan currentWord ke state awal (kosong / length=0).
   I.S. : currentWord sembarang
   F.S. : currentWord kosong (memiliki length 0) */

void ignoreBlanks();
/* Mengabaikan satu atau beberapa BLANK.
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startKata();
/* Kata dibaca dengan prosedur START() yang akan membaca dari input 
   user, akuisisi kata menggunakan CopyWord.
   I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVKata();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyKata();
/* Mengakuisisi kata, menyimpan dalam currentWord.
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void startFileKata(char* path);
/* Kata dibaca dengan prosedur STARTFILE() yang akan membaca dari file pada path, 
   akuisisi kata menggunakan copyKataDenganBlanks.
   I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVFileKata();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure copyKataDenganBlanks */

void copyKataDenganBlanks();
/* Mengakuisisi kata dengan membolehkan blanks, menyimpan dalam currentWord.
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void startLine();
/* Membaca satu line dari user, dengan membolehkan spasi.
   I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

boolean isKataEqual(Word W1, Word W2);
/* Mengembalikan true bila Word W1 sama dengan Word W2. */

boolean isKataInt(Word W);
/* Mengembalikan true apabila seluruh isi Word berupa numerik */

void displayKata(Word W, boolean newLine);
/* Menampilkan isi Word ke layar.
   I.S. : sembarang
   F.S. : Seluruh isi dalam Word telah ditampilkan pada layar */

int kataToInt(Word W);
/* Mengembalikan nilai integer dari Word W */
#endif