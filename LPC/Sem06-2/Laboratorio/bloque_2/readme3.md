
a. ¿Cuál es la diferencia entre char *s = "..." y char s[] = "..." en términos de
memoria?
*s = "...": Cadena literal que se almacena en la sección de memoria de solo lectura.

char s[] = "...": Reserva espacio directamente en el Stack de la función. El compilador copia caracter a caracter la cadena hacia el stack, lo que permite que lo modifiquemos.

b. ¿Por qué intentar modificar un literal de cadena es comportamiento no
definido?
Porque las cadenas literales residen en una zona de memoria que es sistema operativo marca como
protegida contra escritura. Si el programa intenta ejecutar esta acción provocará una interrupción

c. ¿Cuándo conviene cada declaración?
Conviene char *s = "...": Para cuando usemos mensajes fijos y ahorrar algo de memoria y tiempo de CPU.
Conviene char s[] = "...": Para cuando necesitemos modificar el texto.