#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTERM 255

int main(int argc, char *argv[])
{
    /* payload type: Linear list cell */

    typedef struct lin_list
    {
        char* payload;
        struct lin_list *next;
    }LinListCell, *LinList_p;

    char content[MAXTERM+1];


    //Prototypen
    // LinList_p LinListAllocCell(char* payload);
    // void LinListFreeCell(LinList_p junk);
    // void LinListFree(LinList_p *junk);
    // LinList_p LinListInsertFirst(LinList_p *anchor, LinList_p newcell);
    // LinList_p LinListExtractFirst(LinList_p *anchor);

   FILE *in = stdin;

   if(argc > 2)
   {
      fprintf(stderr, "Usage: %s [<file>]\n", argv[0]);
      exit(EXIT_FAILURE);
   }

    in = fopen(argv[1], "r");
    if(!in)
    {
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    //Pogramm:

    LinList_p liste;

    int anzahl = 0;
    char* l;
    
    //Allocate one cell
    LinList_p LinListAllocCell(char *payload){
        LinList_p cell = malloc(sizeof(LinListCell));

        // cell->payload = malloc(sizeof(content));
        cell->payload = strdup(payload);
        cell->next = NULL;

        return(cell);
    }

    //Free one cell
    void LinListFreeCell(LinList_p *junk)
    {
        free(junk -> payload);
        free(junk);
    }

    //free whole list
    void LinListFree(LinList_p *junk)
    {
        if(junk->next == 0)
        {
            LinListFreeCell(junk);
        } else
        {
            LinListFree(junk->next);
        }
        junk = NULL;
    }

    //Insert a cell as first
    LinList_p LinListInsertFirst(LinList_p *anchor, LinList_p *newcell)
    {
        newcell -> next = anchor;
        anchor = newcell;

        return(*anchor);

    }

    //extract the first cell
    LinList_p LinListExtractFirst(LinList_p *anchor)
    {
        if(anchor == NULL)
        {
            printf("Die Liste ist leer");
            return(NULL);
        }
        
        LinList_p newcell = anchor;
        anchor = anchor->next;
        return(newcell);
    }

    //read stdin and build list
    while((l=fgets(content, MAXTERM, in)))
    {
        LinListInsertFirst(&liste, (LinListAllocCell(content)));
        anzahl = anzahl + 1;
    }

    
    //printing in reverse order
    printf("\nReverse order\n==========");
    for(int i = 0; i <= anzahl; i++)
    {
        LinList_p cell = LinListExtractFirst(liste);
        printf("%s\n", cell->payload);
        LinListInsertFirst(liste, (LinListAllocCell(cell)));
        free(cell);
    }

    //printing in the right order
       printf("\nOriginal order\n==========");
    for(int i = 0; i <= anzahl; i++)
    {
        LinList_p cell = LinListExtractFirst(anchor);
        printf("%s\n", cell->payload);
        free(cell);
    }

   if(in!=stdin)
   {
      fclose(in);
   }
   exit(EXIT_SUCCESS);
}