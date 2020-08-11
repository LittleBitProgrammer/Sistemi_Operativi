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

    printf("====================================\n");
    printf("first fd = %d\n", filedes);
    printf("second fd = %d\n", filedes2);
    printf("Newfd = %d\n", newfd);
    printf("====================================\n");

    if(write(filedes,"ciao",4) != 4){
        printf("Error\n");
    }

    if(write(filedes2,"charlie",7) != 7){
        printf("Error\n");
    }

    return 0;
}