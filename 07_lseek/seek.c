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