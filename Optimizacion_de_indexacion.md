# Optimizacion de la indexacion #

Uno de los puntos que nos estuvo preocupando ultimamente fue la performance del indexador, la solucion que habia propuesto antes del cache funcionaria bien, pero sin embargo, solo se aplica a optimizar las consultas, ya que las operaciones de escritura en el indice (arbol b+, diccionarios, linkedblocks, etc...) son iguales con o sin ese cache

Una posible solucion a este problema, es implementar un cache para la escritura, que pueda hacer "escritura demorada"

Se podria implementar mediante un wrapper de la interfaz BPlusNodeDao, la idea basicamente es la misma que el cache de lectura, pero en el sentido de escritura ; es decir: en lugar de tener un cache en memoria de las ultimas N entradas leidas, se puede tener en memoria un cache de las ultimas N entradas escritas, sin escribirlas, y esperar el momento adecuado para envirlas al BPLusNodeDao verdadero

La diferencia de este cache con el de lectura, es que la optimizacion pasa por poder escribir los registros "en memoria" y que sean volcados despues (por ej, inserciones sucesivas de registros a un mismo nodo del bplus, generarian una sola escritura a disco en lugar de varias ), y otra cosa importante a tener en cuenta es que debe contar con un mecanismo para saber que tiene que escribir las entradas (cuando el cache alcance algun tope) y tambien poderle indicar que actualize el archivo