/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "ADT_Mesin_Karakter.h"


#define NMax 100
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
   F.S. : currentWord kosong atau length-nya = 0 */

void ignoreBlanks();
/* Mengabaikan satu atau beberapa BLANK.
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startKata();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void startSentence();

void startFileKata(const char* file_name);
/* Kata dibaca dengan prosedur STARTFILE() yang akan membaca dari file pada path, 
   akuisisi kata menggunakan copySentence.
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

void ADVSentence();

void copyKata();
/* Mengakuisisi kata, menyimpan dalam currentWord.
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void copySentence();

// boolean isEndWord();

void ADVFileKata();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure copySentence */

void copySentence();
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

boolean isKataEqual(Word kata1, Word kata2);
/* Mengembalikan true bila Word kata1 sama dengan Word kata2. */

boolean isKataInt(Word kata);
/* Mengembalikan true apabila seluruh isi Word berupa numerik */

void displayKata(Word kata, boolean newLine);
/* Menampilkan isi Word ke layar.
   I.S. : sembarang
   F.S. : Seluruh isi dalam Word telah ditampilkan pada layar */

int kataToInt(Word kata);
/* Mengembalikan nilai integer dari Word kata */

#endif