#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "variable.h"
// DISPLAY FUNCTION
void clearScreen()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    printf("\033[2J\033[H"); // For Linux/Unix
#endif
}
void printGaris()
{
    for (int i = 0; i < 70; i++)
    {
        printf("-");
    }
    printf("\n");
}
void printGarisDouble()
{
    for (int i = 0; i < 70; i++)
    {
        printf("=");
    }
    printf("\n");
}
void displayPilihan()
{
    printf("\t\t\tALPHALINK RESTAURANT\n\n");
    printf("Pilih Menu\n");
    printf("1. Pesan Makanan\n");
    printf("2. Pesan Minuman\n");
    printf("3. Tampilkan Keranjang\n");
    printf("4. Checkout\n");
    printf("0. Keluar\n");
}
void displayMenu(struct menu *jenis, int size, int total, struct nota *nota, int batas1, int batas2)
{
    printf("\t\tALPHALINK RESTAURANT\n\n");
    printf("DAFTAR HARGA : \n");
    printGaris();
    printf("KODE\tNAMA MENU\t\tHARGA\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t%s\t\tRp.%d.00", jenis[i].kode, jenis[i].nama, jenis[i].harga);
        printf("\n");
    }
    printf("\n*Harga belum termasuk pajak 10%%\n");
    printf("NB : inputkan kode untuk memasukkan ke dalam keranjang\n");
    printf("Diskon 20%% dengan minimal pembelian 500000\n\n");
    int pilihanKe = 0, pilihan[100], jumlah;
    bool isTrue = true;
    do
    {
        printf("Masukkan pesanan (tekan 0 jika ingin keluar) : ");
        scanf("%d", &pilihan[pilihanKe]);
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        if (pilihan[pilihanKe] != 0 && pilihan[pilihanKe] >= batas1 && pilihan[pilihanKe] < batas2)
        {
            printf("Masukkan jumlah = ");
            scanf("%d", &jumlah);
            for (int i = 0; i < size; i++)
            {
                if (pilihan[pilihanKe] == jenis[i].kode)
                {
                    strcpy(nota[total].jenis, jenis[i].nama);
                    nota[total].harga_satuan = jenis[i].harga;
                    nota[total].qty = jumlah;
                    nota[total].jumlah_harga = nota[total].harga_satuan * nota[total].qty;
                    printf("Pesanan %s (Rp.%d.00 x %d) berhasil ditambahkan.\n\n",
                           nota[total].jenis, nota[total].harga_satuan, nota[total].qty);
                    overallPrice += nota[total].jumlah_harga;
                    total++;
                    pilihanKe++;
                }
            }
        }
        else if (pilihan[pilihanKe] == 0)
        {
            isTrue = false;
            break;
        }
        else
        {
            printf("Input Ulang, kode tidak valid\n");
        }
    } while (isTrue);
    clearScreen();
}
void displayNota()
{
    printf("No.\tMenu (Kode)\tHarga Satuan\t   Qty\t\tJumlah Harga\n");
    printGaris();
    int next = 0;
    for (int i = 0; i < totalMakanan; i++)
    {
        printf("%d.\t%s\tRp. %d.00\t   %d\t\tRp. %d.00\n", i + 1, notaMakanan[i].jenis, notaMakanan[i].harga_satuan, notaMakanan[i].qty, notaMakanan[i].jumlah_harga);
        next++;
    }
    for (int i = 0; i < totalMinuman; i++)
    {
        printf("%d.\t%s\tRp. %d.00\t   %d\t\tRp. %d.00\n", next + 1, notaMinuman[i].jenis, notaMinuman[i].harga_satuan, notaMinuman[i].qty, notaMinuman[i].jumlah_harga);
    }
}
void keluar()
{
    int ketik;
    printGaris();
    printf("Ketik 0 untuk kembali ke menu utama : ");
    scanf("%d", &ketik);
    if (ketik == 0)
    {
        clearScreen();
    }
}