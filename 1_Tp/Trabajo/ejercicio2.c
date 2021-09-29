/*
        Escriba un programa que reciba una cantidad variable de nombres de archivo desde la
        línea de comandos. Por cada nombre de archivo el programa debe crear un proceso hijo
        que:

        - Imprima su PGID, PPID, PID y el nombre del archivo; y
        - Use una de las funciones de la familia exec() para ejecutar: wc -l
        nombre_de_archivo.

        Consideraciones:
        - Los procesos hijos se deben ejecutar concurrentemente.
        - El proceso padre debe indicar que proceso hijo va finalizando e indicando de
        que manera finaliza (Normal o por una señal).

        - Si no se pasa ningún nombre de archivo se debe mostrar un mensaje de error.

        - No se puede utilizar la llamada al sistema system().
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define _XOPEN_SOURCE 600

int main(int argc, char **argv){
    
    //- Si no se pasa ningún nombre de archivo se debe mostrar un mensaje de error.
    if(argc == 1){
        printf("Faltan archivos por processar");
        exit(1); //Estamos diciendo que finalizo de manera incorrecta
    }
    int i, estado;
    int proceso;
    for(i=1;i<argc;i++){
        //Por cada nombre de archivo el programa debe crear un proceso hijo que:
        proceso = fork();
        if(proceso==0){
        //Imprima su PGID, PPID, PID y el nombre del archivo; y
        printf("PGID: %d, PPID: %d, PID: %d, nombre del archivo: %s \n", getpgid(0), getppid(), getpid(), argv[i]);
        //Use una de las funciones de la familia exec() para ejecutar: wc -l nombre_de_archivo.
        execlp("wc","wc","-l",argv[i],NULL);
        }
    }

    // El proceso padre debe indicar que proceso hijo va finalizando e indicando de
    // que manera finaliza (Normal o por una señal).
    for(i=1;i<argc;i++){
        proceso = wait(&estado);

        if(WIFEXITED(estado)){
            printf("PID: %d finalizo de manera normal", proceso);
        }
        
        if(WIFSIGNALED(estado)){
            printf("PID: %d finalizo por una señal" , proceso);
        }

    }
}