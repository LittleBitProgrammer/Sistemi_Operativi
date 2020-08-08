/*
* Nome:  copy.c
* Scopo: Copiare ed incollare da un file stadard input a standard output
* data:  08 Agosto 2020
* Autore Roberto Vecchio
*/

// Directive
#include <stdio.h>
#include <unistd.h>

// Costants
#define BUFF 4096

int main(void){
    // Declaration
    int number_byte; // to memorize number of byte to write
    char buffer[BUFF];

    // instructions
    // finchè c'è contenuto da leggere copia nel buffer e scrivi utilizzando il buffer 
    while((number_byte = read(STDIN_FILENO,buffer,BUFF)) > 0){
        if(write(STDOUT_FILENO,buffer,number_byte) != number_byte){
            printf("write error");
        }
    }

    if(number_byte < 0){
        printf("read error");
    }
    //OS Code
    return 0;
}