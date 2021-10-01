/*
Implemente un programa que imprima la lista de entorno, quite del entorno las
variables pasadas como argumentos de línea de comandos y vuelva a imprimir la lista
de entorno. Ejemplo:
$ ./quitar_env SHELL HOME PATH

*/
#include <stdlib.h>
#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[]){
    char **valor;

    for(valor = environ; valor != NULL; valor++){
        printf("%s",*valor);
    }
    printf("\n Eliminando variables \n");
    for(int i=1; i < argc; i++){
        if (unsetenv(argv[i]) == -1){
            printf("Error al eliminar variable de entorno\n");
            exit(1);
        }
    }

    return 0;
}