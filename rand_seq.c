#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000
int main (int argc, char *argv[])
{
    FILE *in = stdin;

    if(argc > 2)
    {
        fprintf(stderr, "Usage: %s [<file>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int anzahl, i, zufall;
    anzahl = atoi(argv[1]);
    srand(time(0));

    for(i=1; i <= anzahl; i++){
        zufall = rand();
        zufall = zufall % MAXNUM;
        printf("%i\n", zufall);
    }

    if(in!=stdin)
    {
        fclose(in);
    }
    exit(EXIT_SUCCESS);
}
