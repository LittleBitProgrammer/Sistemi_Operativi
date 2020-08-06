/*
* Nome:   myls.c
* Scopo:  Elencare i file di una directory
* Autore: Roberto Vecchio
* Data:   08 Luglio 2020
* Build:  cc -o myls myls.c -Wall -I SCADDRESS/include/ -L SCADDRESS/lib/ -lapue
* Example Build: gcc -Wall -o myls myls.c -I /usr/local/include/ -L /usr/local/lib/ -lapue
*/

// Directive
#include <sys/types.h> // include sys types
#include <dirent.h> // Contain DIRECTORY(DIR) stuct type, dirent struct type, opendir() function and closedir() function
#include "apue.h" // to use err_quit() and err_sys() functions

/*
* argc = numero argomenti compreso il comando
* *argv[] = array  di stringhe (coincidono ai comandi presenti nel terminale compreso lo stesso comando lanciato, ad esempio argv[0] = myls )
*/
int main(int argc,char *argv[]){

    // Declaration
    DIR *dp; //declare a pointer to a directory struct
    struct dirent *dirp; // decalare a pointer to a struct of type dirent

    //Instructions

    // If i have entered no parameters, show an error
    // to see if there are no parameters you have to see if argc != 2 because if argc is == to 1 you have entered only command with no parameters
    if(argc != 2){
        err_quit("A single argument (the dir name) is required");
    }

    // If the opendir method that return a pointer to a DIR struct is equal to a NULL pointer(because it not exist or if you have not permission to open it)
    // show an error
    if( (dp = opendir(argv[1])) == NULL ){
        err_sys("Can't open %s", argv[1]);
    }

    // For every sub element of current open dir we have to print it
    // with readdir method of header file dirent.h we return a pointer to the entry point of this dir and the set the stream position to next sub element
    // so we can use a while to cycle every element as next:
    while ((dirp = readdir(dp)) != NULL){
        printf("%s\n", dirp -> d_name);
    }

    // We have to clase the dir that we have opened
    closedir(dp);

    // Operating System Code
    return 0;
}