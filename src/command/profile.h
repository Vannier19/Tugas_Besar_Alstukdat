#ifndef PROFILE_H
#define PROFILE_H

#include <stdio.h>
#include "../ADT/ADT_Kustom.h"
#include "../ADT/ADT_Array_Statik.h"

void show_profile(List users, int idxUser);
int find_idxUser(List users, int jumlahUsers, char *username);

#endif