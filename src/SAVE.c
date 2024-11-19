#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_USERS 50
#define MAX_LEN 10000000

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
} User;

typedef struct {
  char name[MAX_LEN];
  int price;
} Barang;

void SAVE_TO_FILE(Barang barang[], int jumlahBarang, User users[], int jumlahUsers, char *namaFile) {
    // KAMUS LOKAL
    FILE *saveFile;
    int i, j;

    // ALGORITMA
    saveFile = fopen(namaFile, "w"); // Membuka file untuk ditulis
    if (saveFile == NULL) {
        printf("Gagal membuka file untuk menyimpan data.\n");
        return;
    }

    // Menulis jumlah barang
    fprintf(saveFile, "%d\n", jumlahBarang);
    
    // Menulis data barang
    for (i = 0; i < jumlahBarang; i++) {
        fprintf(saveFile, "%d ", barang[i].price);

        // Menulis nama barang dengan benar (tanpa tanda tambahan)
        for (j = 0; barang[i].name[j] != '\0'; j++) {
            fputc(barang[i].name[j], saveFile);
        }

        fprintf(saveFile, "\n");
    }

    // Menulis jumlah pengguna
    fprintf(saveFile, "%d\n", jumlahUsers);
    
    // Menulis data pengguna
    for (i = 0; i < jumlahUsers; i++) {
        fprintf(saveFile, "%d %s %s\n", users[i].money, users[i].name, users[i].password);
    }

    fclose(saveFile); // Menutup file
    printf("Data berhasil disimpan ke file %s.\n", namaFile);
}
// Barang barang[] = {
//     {"AK47", 10},
//     {"Lalabu", 20},
//     {"Ayam Goreng Crisbar", 20}
// };

// User users[] = {
//     {"admin", "alstrukdatkeren", 100},
//     {"praktikan", "kerenbangetkak", 25}
// };

// int main() {
//     SAVE_TO_FILE(barang, 3, users, 2, "data.txt");
//     return 0;
// }
