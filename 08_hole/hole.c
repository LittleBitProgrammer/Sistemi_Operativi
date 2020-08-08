/*
* Nome:   hole.c
* Scopo:  Dimostrare che è possibile creare un buco all'interno dei file attraverso lseek
* Data:   08 Agosto 2020
* Autore: Roberto Vecchio ©
* Build:  gcc -Wall -o hole hole.c -I /usr/local/include -L /usr/local/lib -lapue
*/

// Directive
#include <fcntl.h> // per usare funzione creat
#include "apue.h" // per usare err_sys and lseek

int main(void){
    // Declarations
    int file_descriptor;
    char buffer_one[] = "abcdefghi";
    char buffer_two[] = "ABCDEFGHI";

    // Instructions
    // Se il file creato non può essere creato/aperto ritorna un errore ed esci dal programma
     if ( (file_descriptor = open("file.hole", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR)) == -1){
        err_sys("open error"); // return the error and exit from program
    }

    // ora dobbiamo spostare il programma dalla posizione corrente così da creare un "buco"
    if(lseek(file_descriptor,40,SEEK_CUR) == -1){
        err_sys("seek error"); // return the error and exit from program
    }

    // ora scriviamo oltre il "buco" creato 
    if(write(file_descriptor,buffer_two,9) != 9){
        err_sys("write error"); // return the error and exit from program
    }

    // Ulteriore dimostrazione
    if(lseek(file_descriptor,40,SEEK_CUR) == -1){
        err_sys("seek error"); // return the error and exit from program
    }

    if(write(file_descriptor,buffer_one,9) != 9){
        err_sys("write error"); // return the error and exit from program
    }

    //OS Code
    return 0;
}