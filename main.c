#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "variable.h"
#include "menu.h"
#include "display.h"

// define font-style
// #define RED "\033[31m"
// #define GREEN "\033[32m"
// #define YELLOW "\033[33m"
// #define BLUE "\033[34m"
// #define BOLD "\033[1m"
// #define RESET "\033[0m"

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