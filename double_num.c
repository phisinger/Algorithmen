#include <stdio.h>
#include <stdlib.h>

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
   char s[6];
   int z;
   char* l;

   while((l=fgets(s, 23, in)))
   {
       z = atoi(s);
       z = z*2;
       printf("%d\n", z);
   }

   if(in!=stdin)
   {
      fclose(in);
   }
   exit(EXIT_SUCCESS);
}