#ifndef TEBAK_ANGKA_H
#define TEBAK_ANGKA_H

#include <time.h>
#include "../ADT/mesinkata.h"
#include "../save/save.h"

// *************** Deklarasi Fungsi dan Prosedur ***************
int generate_random_number();
/*Fungsi generate_random_number
 * I.S. : Tidak ada angka acak yang dihasilkan.
 * F.S. : Menghasilkan sebuah angka acak antara 1 hingga 100.
 * 
 * return Sebuah angka integer (1-100) yang dihasilkan secara acak.
 */
void tebakAngkaGame();
/* Prosedur tebakAngkaGame
 * I.S. : User berada di menu permainan dengan sejumlah uang dalam akun.
 * F.S. : User telah bermain "Tebak Angka". Uang akan berkurang sesuai biaya main, 
 *        hadiah akan ditambahkan jika berhasil menebak, dan target angka akan ditampilkan
 *        jika user gagal menebak dalam jumlah kesempatan yang diberikan.
 */

#endif
