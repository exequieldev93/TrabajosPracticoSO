/*
 Para hacer uso de estas funciones implemente un programa que después de limpiar el
entorno, agrega las definiciones de entorno proporcionadas como argumentos de línea
de comandos y finalmente, imprime la lista de entorno actual.Ejemplo:
$ ./modificar_env "GREET = Guten Tag" SHELL=/bin/bash BYE=Ciao

*/
#define _DEFOULD_SOURCE
#include <stdio.h>
#include <stdlib.h>


extern char **environ;

int main(int argc, char *argv[]){

    char **valor;
    if( argc == 1){
        printf("Debe ingresar argumentos\n");
    }
    if (clearenv()==0){
        printf("Error al limipar el etorno \n");
        exit(1);
    }
    //Agrega las definiciones de entorno proporcionadas como argumentos de línea de comandos
    for(int i=1;i < argc;i++){
        if(putenv(argv[i])==0){
            printf("Error al definir la variable de entorno\n");
            exit(1);
        }
    }

    //Imprime la lista de entorno actual
    for (valor = environ; *valor != NULL; valor++){
            printf("%s",*valor);
    }
}