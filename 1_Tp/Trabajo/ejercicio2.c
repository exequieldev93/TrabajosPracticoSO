
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define _XOPEN_SOURCE 600

int main(int argc, char **argv){
    
    
    if(argc == 1){
        printf("Faltan archivos por processar");
        exit(1); 
    }
    int i, estado;
    int proceso;
    for(i=1;i<argc;i++){
        
        proceso = fork();
        if(proceso==0){
        
        printf("PGID: %d, PPID: %d, PID: %d, nombre del archivo: %s \n", getpgid(0), getppid(), getpid(), argv[i]);
        
        execlp("wc","wc","-l",argv[i],NULL);
        }
    }

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