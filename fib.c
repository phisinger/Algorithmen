#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibr(int n){
    if (n<= 2) return 1;
    return (fibr(n-1) + fibr(n-2));
}

int main(int argc, char *argv[])
{
    FILE *in = stdin;

    int erg;
    for(int i = in; i > 0; i--){
        erg = fibr(i);
        printf(erg);
    }
}