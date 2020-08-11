
/*
* Nome: main.c
* Scopo: dimostrare utilizzo di dup2
* Data: 11 Agosto 2020
* Autore: Roberto Vecchio & Carlo Lomello ©
* Build: gcc -Wall -o test test.c
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
    int filedes, filedes2;
    int newfd;

    if((filedes = open("file1.txt",O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR)) == -1 ){
        printf("Error\n");
    }

    printf("first fd = %d\n", filedes);

    if((filedes2 = open("file2.txt",O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR)) == -1){
        printf("Error\n");
    }

    printf("second fd = %d\n", filedes2);

    newfd = dup2(filedes,filedes2);

    if(write(filedes,"ciao",4) != 4){
        printf("Error\n");
    }

    if(write(filedes2,"charlie",7) != 7){
        printf("Error\n");
    }

    return 0;
}