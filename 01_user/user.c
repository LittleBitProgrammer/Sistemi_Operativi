/*
* Nome: user.c
* Scopo: Mostrare lo userID e il GroupUserID
* Autore: Roberto Vecchio
* Data: 09 Luglio 2020
*/

// Directive
#include "apue.h" // to use Operating System function

int main(void){
    // Instructions

    /*
    * getuid() return the userID
    * getgid() return the groupUserID
    */
    printf("uid = %d, gid = %d\n", getuid(), getgid());

    // Operating System Code
    return 0;
}