# Wrappers para cachear resultados #

> Cuando haya que aumentar la performance de las consultas, podriamos implementar un Wrapper para algunas interfaces, que mantengan un Cache de lo q se va leyendo y/o insertando


## Interfaces que podriamos wrappear ##

### BPlusTreeBo ###

> Wrappeando esta interfaz nos permitiria consultar miles de veces seguidas una misma entrada del b+, sin preocuparnos de que esto genere accesos a disco, etc...

### BPlusNodeDao ###

> Si logramos Wrappear el dao de los nodos, podria aumentar la performance del b+ implementando lo que se denomina "Arboles B virtuales", el Wrapper cache seria configurable para permitir definir la prioridad de los nodos, asi se podria asignar mas prioridad a la raiz y a los nodos mas cercanos a la raiz para asegurarse de que esten siempre en memoria y se abarate el costo de recuperacion de elementos


### DocumentDictionary ###

> Wrappeando esta interfaz logramos disminuir considerablemente los accesos a disco para recuperar la informacion de documentos, util en las consultas etc

### Index ###

> Esta puede ser un poco mas complicada de Wrappear, pero wrappearla serviria para resolver eficientemente las consultas paginadas, etc...


> Esta de mas decir que implementarlo de esta manera nos ahorra tener que modificar las implementaciones ya existentes, y nos permite activarlo y desactivarlo con facilidad