#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXITEMS 1000 

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
   
   char s[256];
   char* g[MAXITEMS];
   int z, i = 0;
   char* l;

   while(l=fgets(s, 255, in) && i < 999)
   {
    g[i] = strdup(s);
    i += 1;
   }

   	for(z=i; z>=1; z--)
	{
		printf("%s", g[z-1]);
	}
   
   if(in!=stdin)
   {
      fclose(in);
   }
   exit(EXIT_SUCCESS);
}