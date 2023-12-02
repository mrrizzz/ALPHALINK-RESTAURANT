#include <stdio.h>
// VARIABLE DECLARATION
// variable.h
#ifndef VARIABLE_H
#define VARIABLE_H

struct nota
{
    char jenis[30];
    int harga_satuan;
    int jumlah_harga;
    int qty;
};
struct menu
{
    int kode;
    char nama[30];
    int harga;
};
extern struct nota notaMakanan[100];
extern struct nota notaMinuman[100];

extern int totalMakanan, totalMinuman, overallPrice;

void pesanMakanan();
void pesanMinuman();
void displayMenu(struct menu *jenis, int size, int *total, struct nota *nota, int batas1, int batas2);
void tampilkanKeranjang();
void displayPilihan();
void checkout(int *cont);

#endif // VARIABLE_H
