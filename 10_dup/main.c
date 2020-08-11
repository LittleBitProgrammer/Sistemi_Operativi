#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
    int filedes, newdes;

     if((filedes = open("file1.txt",O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR)) == -1 ){
        printf("Error\n");
    }

    newdes = dup(filedes);

    if(write(filedes,"ciao",4) != 4){
        printf("Error\n");
    }

    if(write(newdes,"charlie",7) != 7){
        printf("Error\n");
    }
    
    return 0;
}