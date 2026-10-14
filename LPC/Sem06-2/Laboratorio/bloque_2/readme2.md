a. Concepto clave: p + 5 no suma 5 bytes, suma 5 * sizeof(int) bytes.
Verifíquenlo imprimiendo (char *)p y (char *)(p+5) y calculando la diferencia
en bytes con (char *)(p+5) - (char *)p.

b. ¿Por qué p[i] es exactamente *(p + i)? ¿Qué dice el estándar C al respecto?
El estándar de C define la sintaxis de corchetes a[b] estrictamente como equivalente a 
*((a) +(b))

c. ¿Por qué 3[p] compila? Explicar la conmutatividad de + y la definición de [].
Porque la sintaxis la define como *((3) + (p)) = *((3) + (p)) = p[3]

d. Trampa: ¿qué pasa con p + 8 (uno más allá del último elemento)? ¿Es válido
crearlo? ¿Se puede desreferenciar?
El estandar de C si permite el calcular esa direccion que se usa a menudo en bucles.
No se puede desreferenciar, el tratar de leerlo dara un comportamiento indefinido.
