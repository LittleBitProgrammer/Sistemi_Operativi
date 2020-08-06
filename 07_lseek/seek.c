/* ---------------------------------------------------------------------------------------------------------------------------
* |Nome:                 |seek.c                                                                                             |
* |Scopo:                |stampare a video se l'operazione lseek è andata a buon fine o meno e se viene eseguita con successo|
* |                      |allegare in output l'offset corrente                                                               |
* |Data:                 |06 Agosto 2020                                                                                     |
* |Autore:               |Roberto Vecchio ©                                                                                  |
* |build:                |gcc -Wall -o seek seek.c                                                                           |
* |execution_test_one:   |./seek < /etc/motd                                                                                 |
* |execution_test_two:   |cat < /etc/motd | ./seek                                                                           |
* |execution_test_three: |./seek < /var/spool/cron/FIFO                                                                      |
  ---------------------------------------------------------------------------------------------------------------------------*/

// DIRECTIVE
#include <stdio.h>  // per usare printf
#include <unistd.h> // per usare lseek e il tipo off_t

int main(void){
    // DECLARATION
    off_t current_position; // per memorizzare posizione corrente

    //INSTRUCTIONS
    /* 
    * Se la posizione corrente ricavata dalla funzione lseek  è uguale a -1, c'è stato un errore oppure il file era:
    ? Una socket
    ? Una FIFO
    ? Una pipe 
    * Per cui stampa "Cannot Seek"
    * Altrimenti, stampa "Seek ok (current position = numero_posizione)"
    */
    if((current_position = lseek(STDIN_FILENO,0,SEEK_CUR)) == -1){
        printf("Cannot seek");
    }else{ 
        printf("Seek ok (current position = %lld)", current_position);
    }

    // OS code
    return 0;
}

// ? Test Build One:
// * Viene eseguito con successo, settando come standartd input /etc/motd

// ? Test Build Two:
// * Fallisce, prima concatena nello standard output lo standard inout /etc/motd e poi utilizza una pipe con il nostro eseguibile
// * ma un pipe con lseek ritorna -1

// ? Test Build Three:
// * Fallisce viene utilizzata una Fifo come argomento della funzione lseek