
---

  * **Nuestro INPUT son archivos de texto unicamente.??**
> Sep.

---

  * **El listado de resultado sera un archivo de salida (pregunto por el volumen del reporte)?**
> Puede serlo, o puede ser salida por pantalla. La última entrega es por pantalla. Pero debe tener cierto diseño para humanos, aún no leemos bits.

---

  * **Nuestro TP se conecta a la WEB?**
> Nop, les vamos a proveer una aplicación para bajar las páginas.

---

  * **En que capa se encuentra el modulo de la catedra?**
> Es la aplicación "bajadora de páginas"

---

  * **Al encontrar caracteres como este &eacute; == (é) se escapean ,cierto??**
> Si están dentro del Body, nuestra área de trabajo, estaría bueno que lo interpreten como el usuario lo leería (osea, cambien las entidades por letras y procesen la palabra), sino perdemos mucho texto en español.

---

  * **La App. debe permitir trabajar con más de un índice invertido??? o con uno solo, y si es más de uno el usuario debe seleccionar con cuál trabajar??**
> No, la idea es que se tenga un solo índice invertido para todos los textos indexados y a indexar, o sea, una vez que se indexaron una cantidad de textos, podría pedirse indexar más, y los términos deberían poder agregarse al índice invertido de forma eficiente.

---

  * **El enunciado en la parte de reconocimiento de términos dice, Los pasoso que se presentan a continuación deben completarse para cada palabra (o secuencia de hasta cinco palabras), ¿A qué se refiere con hasta cinco palabras?**
> Si leés la lista de stop words vas a ver que no solamente están compuestos por palabras sueltas, sino también por secuencias de palabras (como por ejemplo.. en consecuencia, por lo tanto, etc), por lo que deberán tener esto en cuenta a la hora de filtrar las stop words.

---

  * **En la generación de un índice dice que se permitirá modificar el tamaño de los nodos que contengan las entradas de términos, esto son los registros cariables del archivo de datos no???**
> No, esto se refiere a los nodos que contengan los términos. En nuestro caso, haciendo un árbol B+, se refiere a los nodos del árbol, cuyo tamaño debe ser parametrizable.

---

  * **Se puede usar un parser HTML?**
> Si

---

  * **La aplicación que baja los html a disco, en que codificación se los guarda?, Es decir, tenemos que contemplar los casos en que esten en utf-8, utf-16, unicode, etc?**
> Creo que si utilizan una librería de HTML, pueden resolver esto. Lo cambian todo a la codificación de trabajo del sistema (una sola, ASCII, UNICODE, etc.)

---

  * **Tenemos que persistir el index set o se debe levantar en memoria cada vez que se inicia el programa?**
> El arbol lo tenes que persistir en disco y levantar de a partes -que necesites-, no podes tener el index-set todo en memoria, a lo sumo si podes tener una 'rama' del index-set en memoria, pero de hecho la vas a tener que levantar nodo x nodo.

---

  * **Se permite reindexar o dar de baja paginas ya indexadas (Baja/Modificacion de paginas) ?**
> No hay baja/modificacion de registros.

---