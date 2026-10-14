a. Porque el estandar de C exige que %p reciba exclusivamente un (void *). El printf no
convierte los punteros automaticamente sin el cast. Sin el cast se genera un warning por el -Wall.
b. No hay diferencia en las 2 para el compilador. En " int *p, q y int *p, *q " tampoco no hay
diferencias. p es un tipo puntero a int y q un int. En la segunda simplemente se declaran 2 
punteros a int.