#ifndef WORDL3_H
#define WORDL3_H

#include "ADT_Mesin_Kata.h"

#define MAX_ATTEMPTS 6
#define WORD_LENGTH 5 
#define MAX_WORDS 10

int isEqualChar(const char *a, const char *b);
int randomNumberGenerate();
int isCharInWord(char c, char *word);
void printFeedback(char *tebakan, char *targetWord);
void initializeHistory(char history[6][6]);
void printHistory(char history[6][6]);
void playGame(int *saldo);
// void check_word(const char *guess, const char *target, char *result);

#endif
