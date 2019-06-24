#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXCOLS 256
#define MAXROWS 256

typedef struct labyrinth
{
    char lab[MAXROWS][MAXCOLS+2];
    
    int maxrow;
    int startx;
    int starty;
    int lastx;
    int lasty;
    int treasurex;
    int treasurey;
}LabCell, *Lab_p;

// Das Labyrinth testen
int testLab(Lab_p laby)
{
    
    laby -> startx = 0;
    for (int y = 0; y <= (laby -> maxrow); y++)
    {
        int x =0;
        while((laby -> lab[y][x]))
        {
            if((laby -> lab[y][x]) =='S')
            {
                laby -> startx = x;
                laby -> starty = y;
            }

            if((laby -> lab[y][x]) =='X')
            {
                laby -> treasurex = x;
                laby -> treasurey = y;
            }
            x++;
        }
    }
    return (laby -> startx);
}

// Das Labyrinth ausgeben
void printLab(Lab_p laby)
{
    for (int i = 0; i <= (laby -> maxrow); i++)
    {
        printf("%s", (laby -> lab[i]));
    }
}

// Einen Weg durch das Labyrinth finden
Lab_p findLab(Lab_p laby, int aktx, int akty)
{
    

   
    // printf("Find aufgerufen\n");
    // printLab(laby);
    count++;
    //finden
    if ((laby->lab[akty+1][aktx]) == 'X' || (laby->lab[akty][aktx+1]) == 'X' || (laby->lab[akty-1][aktx]) == 'X' || (laby->lab[akty][aktx-1]) == 'X')
    {   
        printf("Schritte: %i\n", count);
        return laby;
    }

    //suchen
    //nach unten laufen
    if ((laby->lab[akty+1][aktx]) == ' ')
    {
        (laby->lab[akty+1][aktx]) = '.';
        akty++;
    }
    // nach rechts laufen
    else if ((laby->lab[akty][aktx+1]) == ' ') 
    {
        (laby->lab[akty][aktx+1]) = '.';
        aktx++;
    }
    // nach oben laufen
    else if ((laby->lab[akty-1][aktx]) == ' ')
    {
        (laby->lab[akty-1][aktx]) = '.';
        akty--;
    }

    // nach links laufen
    else if ((laby->lab[akty][aktx-1]) == ' ')
    {
        (laby->lab[akty][aktx-1]) = '.';
        aktx--;
    }
        

    //.-Fall
    //nach unten laufen
    else if ((laby->lab[akty+1][aktx]) == '.')
    {
        (laby->lab[akty][aktx]) = '!';
        akty++;
    }
    // nach rechts laufen
    else if ((laby->lab[akty][aktx+1]) == '.')
    {
        (laby->lab[akty][aktx]) = '!';
        aktx++;
    }

    // nach oben laufen
    else if ((laby->lab[akty-1][aktx]) == '.')
    {
        (laby->lab[akty][aktx]) = '!';
        akty--;
    }

    // nach links laufen
    else if ((laby->lab[akty][aktx-1]) == '.')
    {
        (laby->lab[akty][aktx]) = '!';
        aktx--;
    }
    else
    {
        printf("ERROR\n");
        return laby;
    }  
    
    return laby;
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

    int count = 0;

    //einlesen
    laby -> maxrow = 0;
    char* l;
    while(l =fgets(laby -> lab[laby -> maxrow], MAXCOLS, in))
    {
        laby -> maxrow++;
    }

    //pruefen
    int test = testLab(laby);

    // Printen
    if(testLab(laby))
    {
        printLab(laby);
        // Debugging
        printf("test: %i\n", test);
        printf("startx: %i\n", laby -> startx);
        printf("starty: %i\n", laby -> starty);
        printf("treasurex: %i\n", laby -> treasurex);
        printf("treasurey: %i\n", laby -> treasurey);
    }
    else
    {
        printf("Das Labyrinth nicht gueltig!");
    }

    laby->lastx = laby->startx;
    laby->lasty = laby->starty;
    int aktx = laby->startx;
    int akty = laby->starty;
    laby = findLab(laby, aktx, akty);
    printLab(laby);



    if(in!=stdin)
    {
        fclose(in);
    }
    exit(EXIT_SUCCESS);
}