Preguntas guía:
a. ¿Por qué en x86-64 los bytes de int v[0] = 1 se ven como 01 00 00 00? Discutir
endianness (little-endian).
Porque estos van de digito byte menos significativo al mas significativo. 1 se representa como 
00000000 00000000 00000000 00000001 en menos significativo es 00000001 que tambien se representa como 2 digitos hexadecimales 01, que es lo que nos devuelve primero. 

b. ¿Qué pasa con el double? ¿Qué significa la mantisa y el exponente en esos
bytes? (Solo conceptualmente, no necesitan decodificarlo.)
El double se almacena con 8 bytes
El exponente representa la escala/potencia de 2 a la que se eleva la cifra
La mantisa representa los digitos significativos del numero.

c. ¿Cómo cambiaría si la máquina fuera big-endian?
En la arquitectura big endian se coloca al byte mas significativo en la direccion de memoria mas baja(al inicio). Entonces en el caso del 1 nos daría:
00 00 00 01
Con el double tambien pasaria los mismo.