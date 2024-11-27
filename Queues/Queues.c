#include <stdio.h>
#include <stdlib.h>

struct kuyruk {
    char elemanlar[10];
    int front, rear;

};


void menu() {
    printf("\n");
    printf("***********************************************************\n");
    printf("*               Yurdum Bank'a hosgeldiniz.                *\n");
    printf("*       Lutfen yapmak istedigin islemi asagidan sec.      *\n");
    printf("***********************************************************\n");
    printf("*                  1.Musteri Girisi                       *\n");
    printf("*                  2.Musteri Cikisi                       *\n");
    printf("*                  3.Bekleyen Musteriler                  *\n");
    printf("*                  4.Cikis                                *\n");
    printf("***********************************************************\n");
    printf("Seciminiz nedir:\n");
}

int main(void) {

    int secim = 0;

    do {
        menu();
        scanf_s("%d", &secim);

        if (secim == 1) {


        }
        else if (secim == 2) {

        }
        else if (secim == 3) {

        }
        else {
            secim == 4;
        }





    } while (secim != 4);










    return 0;
}