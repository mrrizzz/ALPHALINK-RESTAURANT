#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "variable.h"
#include "menu.h"
#include "display.h"
int main()
{
    int pilihan, cont = 1;
    while (cont)
    {
        displayPilihan();
        printf("Pilihan = ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            clearScreen();
            pesanMakanan();
            break;
        case 2:
            clearScreen();
            pesanMinuman();
            break;
        case 3:
            clearScreen();
            tampilkanKeranjang();
            break;
        case 4:
            clearScreen();
            checkout(&cont);
            break;
        case 0:
            cont = 0;
            break;
        }
    }
}