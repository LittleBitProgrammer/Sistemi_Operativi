/*
* Nome:   iobuff.c
* Scopo:  Leggere dallo standard input e scrivere sullo standard output (versione 2)
* Autore: Roberto Vecchio
* Data:   09 Luglio 2020 
* Build:  cc -o iobuff iobuff.c -Wall -I SCADDRESS/include/ -L SCADDRESS/lib/ -lapue
*/

// Directive
#include <stdio.h>  // to use getc, putc printf ecc..
#include <stdlib.h> // to use exit function

int main(void){
    // Declaration
    int c; // variable to iterate every single character

    // Instructions

    // while every single character is not equal to end of file assign it to c
    while ((c = getc(stdin)) != EOF) {
        // if putc return an end of file ther was an error, so we have to show it
        if(putc(c,stdout) == EOF){
            printf("errore di output");
            // Operating System Code
            exit(1);
        }

        // if there was an error on the standard input we have to show it
        // ferror return a not NULL value if there was an error
        if(ferror(stdin)){
            printf("errore di input");
            // Operating System Code
            exit(1);
        }
    }

    // Operating System Code
    return 0;
}
