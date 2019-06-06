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

// Insert a cell as last
LinList_p LinListInsertLast(LinList_p anchor, LinList_p newcell){
    while(anchor){
        anchor = anchor->next;
    }
    anchor -> next = newcell;
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

//extract last list cell
// LinList_p LinListExtractLast(LinList_p *anchor){
//     LinList_p res = *anchor;
//     while(&(*anchor) -> next)
//     {
//         *anchor = &(*anchor) -> next;
//     }
//     &(*anchor) -> next = NULL;
//     return *anchor;

// }

//zaehlen von Elementen



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


/* Ich gehe die Liste durch. bei jedem String guck ich nach, ob ich ihn schon durchsucht habe
*/
void LinList_count(LinList_p *liste)
{
    printf("\nAnzahl\tString\n");
    // int counter = 0;
    while (&liste)
    {
        int counter = 0;
        char* wert = liste -> payload;
        while (&liste)
        {
            if(LinList_Find(liste, wert))
            {
                counter =+ 1;
            }
            liste = &(*liste) -> next;

        }
        printf("%i\t%s",counter, wert);
        liste = &(*liste) -> next;
    }
    
}


//sortieren der Liste
LinList_p LinListSort(LinList_p liste){
    LinList_p l1 = NULL, l2 = NULL, h;
   
   if(!liste ||  !liste->next)
   {
      return liste;
   }
   while(liste)
   {
      h = LinListExtractFirst(&liste);
      LinListInsertFirst(&l1, h);
      if(!liste)
      {
         break;
      }
      h = LinListExtractFirst(&liste);
      LinListInsertFirst(&l2, h);
   }
   l1 = LinListSort(l1);
   l2 = LinListSort(l2);
   
   while((l1) || (l2))
   {
      if(!l2)
      {
         h = LinListExtractFirst(&l1);
      }
      else if(!l1)
      {
         h = LinListExtractFirst(&l2);
      }
      else if(strcmp(l1->payload, l2->payload)<0)
      {
         h = LinListExtractFirst(&l1);
      }
      else
      {
         h = LinListExtractFirst(&l2);
      }
      LinListInsertFirst(&liste, h);
   }
   liste = LinList_revert(&liste);
return liste;

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
        // if(LinList_count(liste, l)){
            LinListInsertFirst(&liste, (LinListAllocCell(content)));
        // }
    }


    //printing in Output
    printf("\nOutput\n==========\n");
    PrintList(stdout, liste);

    // //Sortieren
    // liste = LinListSort(liste);

    //Statistik
    LinList_count(liste);
    
    // //umdrehen
    // liste = LinList_revert(&liste);

    // letztes Element löschen
    // LinList_p lastElement = LinListExtractLast(&liste);

    //printing in the right order
    printf("\nOriginal order\n==========\n");
    PrintList(stdout, liste);

    if(in!=stdin)
    {
        fclose(in);
    }

    exit(EXIT_SUCCESS);
}
