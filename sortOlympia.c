#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTERMS 50
#define MAXITEMS 100000

void printlist(int list[], int v)
{
    for(int k = 0; k < v; k++)
    {
        printf("%i\n", list[k]);
    }
}

void insertSort(int list[], int lang)
{
    
    printf("\nlength: %i\n", lang);
    for(int i = 1; i < lang; i++)
    {
        int j = i;
        while(j>0 && list[j] < list[j-1])
        {
            int temp = list[j];
            list[j] = list[j-1];
            list[j-1] = temp;
            j--;
        }
    }
}

void quickSort(int *links, int *rechts) {
    int *pointer1 = links;
    int *pointer2 = rechts;
    int z, y;
    
    //    Bitweise Verschiebung
    y = *(links + (rechts - links >> 1));
    do {
        while(*pointer1 < y) pointer1++;
        while(*pointer2 > y) pointer2--;
        if(pointer1 > pointer2)
            break;
        z = *pointer1;
        *pointer1 = *pointer2;
        *pointer2 = z;
    } while(++pointer1 <= --pointer2);
    if(links < pointer2)  quickSort(links, pointer2);
    if(pointer1 < rechts) quickSort(pointer1, rechts);
}


long long GetUSecTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec*1000000ll+tv.tv_usec;
}


int main(int argc, char *argv[])
{
    FILE *in = stdin;

    if(argc > 2)
    {
        fprintf(stderr, "Usage: %s [<file>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if(argc == 2)
    {
        in = fopen(argv[1], "r");
        if(!in)
        {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    //Programm
    
    char* l;
    char content[MAXTERMS];
    int element;
    long long time1, time2;
    int quickList[MAXITEMS];
    int sortList[MAXITEMS];
    int insertList[MAXITEMS];
    int v;

    // einlesen
    while(l =fgets(content, MAXTERMS, in))
    {
        if(v == MAXITEMS){
			printf("zu viele Items");
			exit(EXIT_FAILURE);
        }
        sortList[v++] = atoi(content);
    }

    //Listenkopien erzeugen
    for(int v = 0; v < MAXITEMS; v++)
    {
        insertList[v] = sortList[v];
        quickList[v] = sortList[v];
    }

    printf("UNSORTIERT\n\n");
    if(v <= 100) { printlist(sortList, v); }
    //Mit InsertSort sortieren
    time1 = GetUSecTime();
    insertSort(insertList, v);
    time2 = GetUSecTime();

    printf("SORTIERT MIT INSERTSORT:\n\n");
    if(v <= 100) {printlist(insertList, v); }
    long long insertres = time2-time1;
    printf("\nInsertSort time: %lld microsec\n", insertres);

    //Mit QuickSort sortieren
    time1 = GetUSecTime();
    quickSort(quickList,quickList+v-1);
    time2 = GetUSecTime();

    printf("SORTIERT MIT QUICKSORT:\n\n");
    if(v <= 100) {printlist(quickList, v); }
    long long quickres = time2-time1;
    printf("\nQuickSort time: %lld microsec\n", quickres);

    // Verhaeltnis
    long double quo = quickres/insertres;
    printf("Quicksort war %Lf-mal schneller als InsertSort\n", quo);
    

    if(in!=stdin)
    {
        fclose(in);
    }
    exit(EXIT_SUCCESS);
}