/*
* Nome: process.c
* Scopo: Mostrare id del processo avviato
* Data: 10 Luglio 2020
* Build: cc -o process process.c -Wall
*/

// Directive
 #include "apue.h" // To include getpid() function and other...

 int main(void){
     // Instructions
     printf("Hello world from process ID %d\n", getpid());
     
     // operating System Code
     return 0;
 }