#ifndef Kustom
#define Kustom


#define MAX_ITEMS 100
#define MAX_USERS 50
#define MAX_STR 100
#define MAX_LEN 100
typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
} User;


typedef struct {
  char name[MAX_LEN];
  int price;
} Barang;
#endif
