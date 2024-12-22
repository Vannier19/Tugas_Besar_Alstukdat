#include <stdio.h>
#include "Cart.h"

void CreateCart(Map *cart) {
    CreateEmptyMap(cart);
}

void CartAdd(Map *cart, ListDin storeList, Word itemName, int quantity) {
    if (IsFullMap(*cart)) {
        printf("---------------------------------------\n");
        printf("Keranjang penuh!\n");
        printf("---------------------------------------\n");
        return;
    }

    // Cek apakah barang ada di dalam storeList
    boolean found = false;
    int storeIdx = 0;
    Word storeItemName;
    
    for (int i = 0; i < listLength(storeList); i++) {
        // Convert store item name to Word for comparison
        int j;
        for (j = 0; ELMT(storeList, i).name[j] != '\0'; j++) {
            storeItemName.TabWord[j] = ELMT(storeList, i).name[j];
        }
        storeItemName.Length = j;
        
        if (isKataEqual(itemName, storeItemName)) {
            found = true;
            storeIdx = i;
            break;
        }
    }

    if (!found) {
        printf("---------------------------------------\n");
        printf("Barang tidak ditemukan dalam toko!\n");
        printf("---------------------------------------\n");
        return;
    }

    // Mencari item yang sama di keranjang
    int cartIdx = 1;
    boolean foundInCart = false;
    
    while (cartIdx <= cart->Count && !foundInCart) {
        Word cartItemName;
        int k;
        for (k = 0; cart->Elmt[cartIdx].Item.name[k] != '\0'; k++) {
            cartItemName.TabWord[k] = cart->Elmt[cartIdx].Item.name[k];
        }
        cartItemName.Length = k;

        if (isKataEqual(itemName, cartItemName)) {
            foundInCart = true;
            break;
        }
        cartIdx++;
    }

    if (foundInCart) {
        // Update quantity jika item sudah ada
        cart->Elmt[cartIdx].Kuantitas += quantity;
        cart->Elmt[cartIdx].Total = cart->Elmt[cartIdx].Kuantitas * cart->Elmt[cartIdx].Item.price;
    } else {
        // Tambah item baru
        cart->Count++;
        // Copy nama item dari Word ke cart menggunakan ADT_Mesin_Kata
        for (int i = 0; i < itemName.Length; i++) {
            cart->Elmt[cart->Count].Item.name[i] = itemName.TabWord[i];
        }
        cart->Elmt[cart->Count].Item.name[itemName.Length] = '\0';
        
        cart->Elmt[cart->Count].Item.price = ELMT(storeList, storeIdx).price;
        cart->Elmt[cart->Count].Kuantitas = quantity;
        cart->Elmt[cart->Count].Total = quantity * cart->Elmt[cart->Count].Item.price;
    }
    
    printf("---------------------------------------\n");
    printf("Berhasil menambahkan item ke keranjang!\n");
    printf("---------------------------------------\n");
}


void CartRemove(Map *cart, Barang item, Word name, int quantity) {
    int foundIdx = -1;
    for (int currentIdx = 1; currentIdx <= cart->Count; currentIdx++) {
        Word currentName;
        int i;
        for (i = 0; i < MAX_LEN && cart->Elmt[currentIdx].Item.name[i] != '\0'; i++) {
            currentName.TabWord[i] = cart->Elmt[currentIdx].Item.name[i];
        }
        currentName.Length = i;

        // Cocokkan nama barang
        if (isKataEqual(currentName, name)) {
            foundIdx = currentIdx;
            break;
        }
    }

    if (foundIdx == -1) {
        // Barang tidak ditemukan dalam keranjang
        printf("---------------------------------------\n");
        printf("Barang tidak ada di keranjang belanja!\n");
        printf("---------------------------------------\n");
        return;
    }

    // Barang ditemukan, periksa kuantitas
    if (cart->Elmt[foundIdx].Kuantitas >= quantity) {
        // Kurangi kuantitas
        cart->Elmt[foundIdx].Kuantitas -= quantity;
        cart->Elmt[foundIdx].Total = cart->Elmt[foundIdx].Kuantitas * cart->Elmt[foundIdx].Item.price;

        // Hapus elemen jika kuantitas menjadi nol
        if (cart->Elmt[foundIdx].Kuantitas == 0) {
            for (int i = foundIdx; i < cart->Count; i++) {
                cart->Elmt[i] = cart->Elmt[i + 1];
            }
            cart->Count--;
        }

        printf("---------------------------------------\n");
        printf("Berhasil mengurangi %d ", quantity);
        displayKata(name, false);
        printf(" dari keranjang belanja!\n");
        printf("---------------------------------------\n");

    } else {
        // Kuantitas yang diminta lebih besar dari yang tersedia
        printf("---------------------------------------\n");
        printf("Tidak berhasil mengurangi, hanya terdapat %d ", cart->Elmt[foundIdx].Kuantitas);
        displayKata(name, false);
        printf(" pada keranjang!\n");
        printf("---------------------------------------\n");
    }
}

void CartShow(Map *cart) {
    if (IsEmptyMap(*cart)) {
        printf("---------------------------------------\n");
        printf("Keranjang kamu kosong!\n");
        printf("---------------------------------------\n");
        return;
    }
    printf("---------------------------------------\n");
    printf("Berikut adalah isi keranjangmu.\n\n");
    printf("%-10s %-20s %-10s\n", "Kuantitas", "Nama", "Total");
    printf("---------------------------------------\n");

    for (int i = 1; i <= cart->Count; i++) {
        Word itemName;
        int j;
        // Salin nama item ke itemName
        for (j = 0; cart->Elmt[i].Item.name[j] != '\0'; j++) {
            itemName.TabWord[j] = cart->Elmt[i].Item.name[j];
        }
        itemName.TabWord[j] = '\0'; // Menambahkan terminator string
        itemName.Length = j;
        // Cetak isi keranjang dengan format tabel
        printf("%-10d %-20s %-10d\n", 
               cart->Elmt[i].Kuantitas, 
               itemName.TabWord, 
               cart->Elmt[i].Total);
    }
    printf("---------------------------------------\n");
    printf("Total biaya yang harus dikeluarkan adalah %d.\n", getTotalCost(cart));
    printf("---------------------------------------\n");

}

int getTotalCost(Map *cart) {
    int total = 0;
    for (int i = 1; i <= cart->Count; i++) {
        total += cart->Elmt[i].Total;
    }
    return total;
}

void CartPay(User *user) {
    Map *cart = &(user->keranjang);
    int *userBalance = &(user->money);
    printf("---------------------------------------\n");
    printf("Kamu akan membeli barang-barang berikut.\n");
    CartShow(cart);
    
    int totalCost = getTotalCost(cart);
    printf("---------------------------------------\n");
    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalCost);
    
    startLine();
    if (compareKata(currentWord, "Ya") == 1) {
        if (*userBalance >= totalCost) {
            
            // Update balance and clear cart
            *userBalance -= totalCost;

            // Cari item dengan nama leksikografis terbesar
            int maxIdx = 1;
            for (int i = 2; i <= cart->Count; i++) {
                if (compareStrings(cart->Elmt[i].Item.name, cart->Elmt[maxIdx].Item.name) > 0) {
                    maxIdx = i;
                }
            }

            // Tambahkan ke history
            Stack *history = &(user->riwayat_pembelian);
            ItemStack newHistoryItem;
            copyString(newHistoryItem.item.name, cart->Elmt[maxIdx].Item.name);
            newHistoryItem.item.price = cart->Elmt[maxIdx].Total;
            PushStack(history, newHistoryItem);

            CreateEmptyMap(cart);
            printf("---------------------------------------\n");
            printf("Selamat kamu telah membeli barang-barang tersebut!\n");
            printf("---------------------------------------\n");

        } else {
            printf("---------------------------------------\n");
            printf("Yahhh, Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", *userBalance);
            printf("---------------------------------------\n");
        }
    }
}