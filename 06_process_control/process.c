/*
* Nome: process.c
* Scopo: Legge i comandi dallo standar input e li esegue
* Data:  10 Luglio 2020
* Autore: Roberto Vecchio
* Build: cc -o process process.c -Wall -I SCADDRESS/include/ -L SCADDRESS/lib/ -lapue
*/

// Directive
#include <sys/types.h> // to use pid_t, type that identify a process ID
#include <sys/wait.h> 
#include "apue.h" // to use costant MAXLINE and other functions like err_sys ecc..

int main(void){
    // Declaration
    char buff[MAXLINE]; // Initialize buffer with maxline length (4096)
    pid_t pid; // variable to store process ID (this is an int)
    int status;

    // Instructions
    printf("%% "); // To print prompt (%% print %)

    // Until while command entered is Null do this
    while(fgets(buff,MAXLINE,stdin) != NULL){
        // Replace \n with 0 (In Ascii is equal to NULL)
        buff[strlen(buff) - 1] = 0;
        // if fork execution return < 0 show an error
        if((pid = fork()) < 0){
            err_sys("fork error");
        } else if (pid == 0){ // else success execute command
            execlp(buff,buff,(char *) 0);
            err_ret("couldn't execute: %s", buff);
            // Operating System code
            exit(127);
        }
        //if waitpid returns an error show it
        if((pid = waitpid(pid, &status, 0)) < 0){
            err_sys("waitpid error");
            printf("%% ");
        }
    }

    // Operating System Code
    return 0;
}