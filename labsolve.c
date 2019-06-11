#include <stdio.h>
#include <stdlib.h>

#define MAXCOLS 256
#define MAXROWS 256

typedef struct labyrinth
{
   char lab[MAXROWS][MAXCOLS+2];
//    long costs[MAXCOLS][MAXROWS];
//    long bestx[MAXCOLS][MAXROWS];
//    long besty[MAXCOLS][MAXROWS];
   int maxrow;
   int startx;
   int starty;
   int treasurex;
   int treasurey;
}LabCell, *Lab_p;

void testLab(Lab_p laby)
{
    for (int i = 0; i <= (laby -> maxrow); i++)
    {

    }
}

void printLab(Lab_p laby)
{

    for (int i = 0; i <= (laby -> maxrow); i++)
    {
        printf("%s", (laby -> lab[i]));
    }
    
    
}

    int main(int argc, char *argv[])
    {
    FILE *in = stdin;
    Lab_p laby = malloc(sizeof(LabCell));

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

    //einlesen
    laby -> maxrow = 0;
    char* l;
    while(l =fgets(laby -> lab[laby -> maxrow], MAXCOLS, in))
    {
        laby -> maxrow++;
    }

    //pruefen
    // testLab(laby);

    // Printen
    printLab(laby);



    if(in!=stdin)
    {
        fclose(in);
    }
    exit(EXIT_SUCCESS);
}