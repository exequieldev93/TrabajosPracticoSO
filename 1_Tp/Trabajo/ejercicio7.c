#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if(argc == 3 && atoi(argv[2])>0){
        for(int i= 0; i < 10; i++){
           
            if(fork()==0){
                execlp(argv[1],argv[1],NULL);
                printf("Error de ejecucion");
                exit(0);
            }
            sleep(atoi(argv[2]));
        }
    }else{
        printf("El valor numero es menor o igual a cero");
    }

}