// Keranjang.h
#ifndef Keranjang_H
#define Keranjang_H

#include "../ADT/ADT_Kustom_Barang.h"
#include "../ADT/ADT_Kustom.h"
#include "../ADT/ADT_Mesin_Kata.h"
#include "../ADT/ADT_Map.h"
#include "store_list.h"

void CreateCart(Map *cart);
void CartAdd(Map *cart, ListDin storeList, Word itemName, int quantity);
void CartRemove(Map *cart, Barang item, Word name, int quantity);
void CartShow(Map *cart);
int getTotalCost(Map *cart);
void CartPay(User *user);

#endif