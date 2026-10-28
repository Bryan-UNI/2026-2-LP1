Preguntas guía:
a. ¿Cuál es la diferencia fundamental entre malloc y calloc? ¿Cuándo conviene
uno u otro?
Malloc: Asigna un bloque de memoria sin inicializar, lo que contiene valores indeterminados(basura)
Conviene usarlo cuando se va escribir o llenar inmediatamente todas las pocisiones.

Calloc: Asigna un bloque de memoria inicializando todas las pocisiones con 0 para evitar valores indeterminados. Conviene usarlo cuando se necesite un arreglo que este limpio desde el segundo cero.


b. ¿Por qué calloc(n, size) es preferible a malloc(n * size) + memset(..., 0, ...)?
(Pista: overflow en n * size.)
malloc(n * size): Si la multiplicación es gigantesca el resultado se desvorda y nos dará un valor menor. Se reservará menos espacio y al momento de escrivbir los datos en el programa ocurrira un desbordamiento de buffer.

calloc(n, size): Recibe ambos valores por separado, calculando la multiplicacion de forma segura y en caso de detectar un desbordamiento, nos devolvera un NULL.


c. ¿Qué devuelve malloc cuando no puede reservar? ¿Cómo se maneja ese
error?
Cuando se quede sin memoria nos devuelve un puntero NULL. Para manejar este error se recomiendo verificar con un if luego de la asignación de memoria.