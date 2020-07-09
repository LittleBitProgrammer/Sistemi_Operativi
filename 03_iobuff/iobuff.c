/*
* Nome:   iobuff.c
* Scopo:  Leggere dallo standard input e scrivere sullo standard output
* Autore: Roberto Vecchio
* Data:   09 Luglio 2020 
* Build:  cc -o iobuff iobuff.c -Wall -I SCADDRESS/include/ -L SCADDRESS/lib/ -lapue
*/

// Directive
// - LIB
#include "apue.h" // To use macro STDIN_FILENO and STDOUT_FILENO and other functions

// - COSTANTS
#define BUFFSIZE 8192

int main(void){
    // Declaration
    int n; // number of byte returned by read
    char buf[BUFFSIZE]; // buffer

    // Instructions  

    // while there are thing to read n would be > 0
    while( (n = read(STDIN_FILENO,buf,BUFFSIZE)) > 0){
        // if we want to write n byte and the return value is not equal to n we ha an error in write operation, so we have to show to the user
        if (write(STDOUT_FILENO,buf,n) != n)
        {
            err_sys("write error");
        }
    }

    // if n < 0 we have an error in the read operation, so we have to show to the user 
    if(n < 0){
        err_sys("read error");
    }

    // Operating System Code
    return 0;
}