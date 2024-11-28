#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct kuyruk {
    char elemanlar[MAX];
    int front, rear;

};

void init(struct kuyruk* q) {
    q->front = 0;
    q->rear = -1;
    
}

int empty(struct kuyruk* q)
{
    return ((q->front == q->rear) ? 1 : 0);
}

int remove(struct kuyruk* q)
{
    if (empty(q)) {
        printf("Queue underflow");
        exit(1);
    }
    if (q->front == MAX - 1)
        q->front = 0;
    else
        (q->front)++;
    return (q->elemanlar[q->front]);
}
int insert(struct kuyruk* q, int x)
{
    if (q->rear == MAX - 1)
        q->rear == 0;
    else
        (q->rear)++;
    if (q->rear == q->front) {
        printf("Queue overflow");
        exit(1);
    }
    q->elemanlar[q->rear] = x;
    return;
}


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
        
        struct kuyruk k;
        init(&k);
        k.front = k.rear = MAX - 1;
        
        menu();
        scanf_s("%d", &secim);

        if (secim == 1) {


        }
        else if (secim == 2) {

        }
        else if (secim == 3) {

        }
        else {
            
            secim = 4;
            
        }





    } while (secim != 4);










    return 0;
}