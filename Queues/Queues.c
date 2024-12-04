#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queues.h"

#define MAX 10
#define NAME_LENGTH 50 

struct kuyruk {
    char elemanlar[MAX][NAME_LENGTH];
    int front, rear;
};

void init(struct kuyruk* q) {
    q->front = -1;
    q->rear = -1;
}

int empty(struct kuyruk* q) {
    return (q->front == -1);
}

int full(struct kuyruk* q) {
    return ((q->rear + 1) % MAX == q->front);
}

void insert(struct kuyruk* q, char isim[]) {
    if (full(q)) {
        printf("Kuyruk dolu. Daha fazla musteri eklenemez.\n");
        return;
    }
    if (empty(q)) {
        q->front = 0;
        q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % MAX;
    }
    strncpy(q->elemanlar[q->rear], isim, NAME_LENGTH - 1);
    q->elemanlar[q->rear][NAME_LENGTH - 1] = '\0';
    printf("%s kuyruga eklendi.\n", isim);
}

char* dequeue(struct kuyruk* q) {
    if (empty(q)) {
        printf("Kuyruk bos. Cikarma yapilamiyor.\n");
        exit(1);
    }
    char* isim = q->elemanlar[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % MAX;
    }
    return isim;
}

void goster(struct kuyruk* q) {
    if (empty(q)) {
        printf("Bekleyen müsteri yok.\n");
        return;
    }

    printf("Bekleyen müsteriler: ");
    int i = q->front;
    while (1) {
        printf("%s ", q->elemanlar[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void menu(struct kuyruk* q) {
    printf("\n");
    printf("***********************************************************\n");
    printf("*               Yurdum Bank'a hosgeldiniz.                *\n");
    if (!empty(q)) { // Kuyruk bos degilse siradaki kisiyi göster
        printf("*       Siradaki musteri: %s                              *\n", q->elemanlar[q->front]);
    }
    else {
        printf("*       Su anda sirada bekleyen musteri yok.             *\n");
    }
    printf("*       Lutfen yapmak istedigin islemi asagidan sec.      *\n");
    printf("***********************************************************\n");
    printf("*                  1. Musteri Girisi                      *\n");
    printf("*                  2. Musteri Cikisi                      *\n");
    printf("*                  3. Bekleyen Musteriler                 *\n");
    printf("*                  4. Cikis                               *\n");
    printf("***********************************************************\n");
    printf("Seciminiz nedir: ");
}

int main(void) {
    int secim = 0;
    struct kuyruk k;
    init(&k);

    do {
        menu(&k);
        scanf("%d", &secim);

        if (secim == 1) {
            char isim[NAME_LENGTH];
            printf("isminizi Giriniz: ");
            scanf(" %[^\n]%*c", isim);
            insert(&k, isim);
        }
        else if (secim == 2) {
            if (!empty(&k)) {
                char* cikti = dequeue(&k);
                printf("%s siradan ayrildi.\n", cikti);
            }
            else {
                printf("Kuyruk bos.\n");
            }
        }
        else if (secim == 3) {
            goster(&k);
        }
        else if (secim == 4) {
            printf("Çikis yapiliyor...\n");
        }
        else {
            printf("Geçersiz seçim.\n");
        }
    } while (secim != 4);

    return 0;
}
