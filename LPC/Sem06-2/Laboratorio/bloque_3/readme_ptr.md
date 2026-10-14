a. ¿Por qué void dividir(int a, int b, int c, int r) no funcionaría? (Paso por valor.)
Paso por valor: La función recibe copias locales de c y r. Cualquier modificación dentro de dividir afecta únicamente a esas copias y se destruye al salir, sin modificar las variables originales del main.

b. ¿Cuál es la diferencia entre int *p y int **pp?
Diferencia de nivel de indirección: int *p es un puntero simple que almacena la dirección de un entero (int). int **pp es un doble puntero que almacena la dirección de otro puntero (int *).

c. ¿Por qué la función reservar_entero necesita int ** y no int *? Es el mismo
problema que dividir, pero un nivel más arriba.
Modificación de una dirección de memoria: Al llamar a malloc, se quiere modificar la dirección a la que apunta un int *p del main. Como C pasa los argumentos por valor, para alterar la variable p misma (y no una copia) se debe pasar su dirección (&p), lo que exige recibir un int **pp.

d. Cuidado: ¿quién libera la memoria reservada dentro de reservar_entero?
¿Por qué es una decisión de diseño importante? Discutir.
Liberación y gestión de memoria: La libera el llamador (main) invocando free(p). Es una decisión de diseño crítica porque la función asigna memoria en el Heap pero no conoce el ciclo de vida del dato; si el main no asume la responsabilidad de liberarlo, se produce una fuga de memoria (memory leak).