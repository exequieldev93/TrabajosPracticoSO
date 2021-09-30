/*
b) Estudie el uso de getenv(), putenv(), setenv(), unsetenv() y clearenv().

*/
#include <stdio.h>>

char *getenv(const char *name);
/*
La función getenv() recupera valores individuales desde el entorno del proceso.

Dado el nombre de una variable de entorno, getenv() retorna un puntero al correspondiente valor string. 
Así, por ejemploi /bin/bash sería devuelto si SHELL fue especificado  como el argumento name. 
Si no existe variable de entorno con el nombre especificado, entonces getenv() 
retorna NULL.

Hay que tomar nota de las siguientes consideraciones de portabilidad cuando usamos getenv():

        SUSv3 estipula que una aplicación no debería modificar la cadena retornada por getenv(). 
        Esto porque (en la mayoría de las implementaciones) esta cadena es actualmente parte del entorno 
        (por ejemplo, el value en parte de la cadena de name=value). 
        Si necesitamos modificar el valor d una variable de entoro, entonces podemos utilizar las funciones 
        setenv() o putenv().

        SUSv3 permite una implementación de getenv() para retornar su resultando usando un buffer ubicado 
        estáticamente que puede ser sobreescrito por llamadas subsecuentes a getenv(), setenv(), putenv(), 
        o unsetenv(). 
*/

int putenv(char *string);
/*
A veces, es útil para un proceso modificar su entorno. Una razón es hacer un cambio que es visible en todos 
los procesos hijos subsecuentemente creados por ese proceso. Otra posibilidad es que nosotros queramos 
establecer una variable que es visible para un nuevo programa para ser cargado en memoria de este proceso. 
En este sentido, el entorno no es solo una forma de comunicación interprocesos, pero además un método 
de comunicación interprograma.

La función putenv() añade una nueva variable al entorno del proceso llamante o modifica el valor de una 
variable existente. 

El argumento string  es un puntero a una cadena de la forma name=value. Después de la llamada putenv(), 
este string es parte del entorno. En otras palabras, en lugar de duplicar la cadena apuntada por string, 
uno de los elementos de entorno será establecido para apuntar la misma localización que string. 
putenv() retorna un valor diferente de cero, más bien -1.

*/

int setenv(const char * name, const char *value, int overwrite);

/*
La función setenv() es una alternativa a putenv() para añadir una variable al entorno.
La función setenv() crea una nueva variable de entorno ubicado en un buffer de memoria para una cadena
 de la forma name=value, y copiando las cadenas apuntadas por name y value dentro de ese buffer.
 Note que no necesitamos suministrar un signo igual al final de name o al inicio de value, porque setenv() 
 añade este carácter cuando agrega la nueva definición al entorno. 

 La función setenv() no cambia el entorno si la variable identificada por name ya existe y overwrite tiene
  el valor 0. Si overwrite no es cero, el entorno siempre cambia.

 El hecho de que setenv () copie sus argumentos significa que, a diferencia de putenv(), podemos modificar
 posteriormente el contenido de las cadenas apuntadas por name y value sin afectar el entorno. También 
 significa que el uso de variables automáticas como argumentos para setenv() no causa ningún problema. 
*/

int unsetenv(const char *name);

/*
La función unsetenv() elimina la variable identificada por name del entorno. 

Como con setenv(), name no debe incluir un signo igual.

Ambos setenv() y unsetenv() derivan de BSD, y son menos extendidos que putenv(). 
Aunque no están definidos en el estándar original POSIX.1 o en SUSv2, están incluidos en SUSv3.

*/

int clearenv(void);

/*
En algunas circunstancias, el uso de setenv() y clearenv() pueden dirigir fuga de memoria de un programa. 
Como vimos antes, setenv() dirige un buffer de memoria que es entonces hecho parte del entorno. 
Cuando nosotros llamamos a clearenv(), no es gratis este buffer. Un programa que repetidamente emplea 
esas dos funciones firmemente fugarían memoria. En la práctica es imposible que esto sea un problema, 
porque un programa típicamente llama a clearenv() solo una vez al inicio, para eliminar todas las entradas 
del entorno que heredó de su predecesor (es decir, el programa que llamo a exec() para iniciar este programa). 
*/