#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTERM 256

/* payload type: Linear list cell */
typedef struct lin_list
{
    char* payload;
    struct lin_list *next;
}LinListCell, *LinList_p;


//Create new Cell
void LinListFreeCell(LinList_p junk)
    {
        free(junk -> payload);
        free(junk);
    }

//Allocate one cell
LinList_p LinListAllocCell (char* payload)
{
    LinList_p cell = malloc(sizeof(LinListCell));
    cell->payload = strdup(payload);
    cell->next = NULL;
    return(cell);
}


//free whole list
void LinListFree(LinList_p *junk)
{
    if(*junk)
    {
        LinListFreeCell(*junk);
        LinListFree(&(*junk)->next);
        *junk = NULL;
    }
}

//Insert a cell as first
LinList_p LinListInsertFirst(LinList_p *anchor, LinList_p newcell)
{
    newcell->next = *anchor;
    *anchor = newcell;

    return(*anchor);

}

//extract first list cell
LinList_p LinListExtractFirst(LinList_p *anchor)
{
    LinList_p res = *anchor;
    if(res)
    {
        *anchor =res->next;
            res->next=NULL;
    }
    
    return res;
}

//Umdrehen
LinList_p LinList_revert(LinList_p *anchor)
{
      LinList_p newListe = NULL, platz;
    
    while(*anchor)
    {
        platz = LinListExtractFirst(anchor);
        LinListInsertFirst(&newListe, platz);
    }
    return (newListe);
}

//Finden von Elementen
LinList_p LinList_Find(LinList_p liste, char* value)
{
    while(liste){
        if(strcmp(liste->payload,value)==0){
            return liste;
        }
        liste = liste->next;
    }
    return NULL;
}

//alles ausgeben
void PrintList(FILE* out, LinList_p liste)
{
    while (liste)
    {
        fprintf(stdout, "%s", liste->payload);
        liste = liste->next;
    }
    
}



int main(int argc, char *argv[])
{
    char content[MAXTERM];
    FILE *in = stdin;

    if(argc > 2)
    {
        //fprintf(stderr, "\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if(argc == 2)
    {
        in = fopen(argv[1], "r");
        if(!in){
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    //Pogramm:

    LinList_p liste = NULL;
    int anzahl = 0;
    char* l;

    //read stdin and build list
    while((l =fgets(content, MAXTERM, in)))
    {
        if(!LinList_Find(liste, l)){
            LinListInsertFirst(&liste, (LinListAllocCell(content)));
        }
    }

    //printing in reverse order
    printf("\nReverse order\n==========\n");
    PrintList(stdout, liste);

    //umdrehen
    liste = LinList_revert(&liste);

    //printing in the right order
    printf("\nOriginal order\n==========\n");
    PrintList(stdout, liste);

    if(in!=stdin)
    {
        fclose(in);
    }

    exit(EXIT_SUCCESS);
}
