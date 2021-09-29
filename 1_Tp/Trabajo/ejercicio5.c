/*
Indique que procesos corresponden al grupo de procesos creado por el hijo1.
  Los procesos correspondiente al grupo crado por el hijo uno son:
      _Hijo 4 o proceso 4
- ¿Existen procesos zombies? Si la respuesta es afirmativa, indique cuáles?
      _No
- ¿Existen procesos huérfanos? Si la respuesta es afirmativa, indique cuáles?
      _No
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void){
    pid_t proceso1;
    pid_t proceso2;

    proceso1 = fork();
    if(proceso1 == 0){
        pid_t proceso3;
        pid_t proceso4;
        int estado;
        pid_t p;
        proceso3 = fork();
        if (proceso3 == 0)
        {
            sleep(10);
            printf("Proceso3 PID: %d durmio 10 segundos....\n",getpid());
            exit(0);
        }
        setpgid(0, 0);
        proceso4 = fork();
        if (proceso4 == 0)
        {
            sleep(10);
            printf("Proceso4 PID: %d durmio 10 segundos....\n", getpid());
            exit(0);
        }
        exit(0);
    }
    
    proceso2 = fork();
    if(proceso2 == 0){
        sleep(10);
        printf("Proceso2 PID: %d durmio 10 segundos....\n",getpid());
        exit(0);
        
    }
    sleep(20);
    printf("El Padre PID: %d durmio 20 segundos....\n", getpid());
    exit(0);
    
}