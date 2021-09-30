/*
Como debe cambiar la cabecera de main() para acceder a las variables de entorno del
proceso. Qué problema existe con esta forma de acceder a las variables de entorno.

El método alternativo para acceder a la lista de entorno es declarar un tercer argumento a la función main():

    int main (int argc, char *argv[], char *envp[])

Este argumento se puede tratar de la misma froma que en el entorno, con la 
diferencia de que su alcance es local a main().  Aunque esta característica 
está ampliamente implementada en sistemas UNIX, su uso debe evitarse ya que, 
además de la limitación del alcance, no se especifica en SUSv3.

*/

