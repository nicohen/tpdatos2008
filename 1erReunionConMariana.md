**Consideraciones analizadas con Mariana:**

  * **INDICES INVERTIDOS**
    * El arbol B+ va a contener un IndexSet y un SecuentialSet
      * El _IndexSet_ estará persistido en disco y se levantaran los nodos onDemand
      * El _SecuentialSet_ contendra los nodos encadenados, los cuales contendrán conjuntos de palabras asociadas a un offset que apunta a los documentos que la contienen
    * Los documentos estaran en un archivo relativo que soporta encadenamiento, estos documentos seran referenciados a través del offset indicado en el arbol B+

  * **Palabras a indexar**
    * Las palabras a indexar deben tener como minimo 3 caracteres

  * **Logica para terminos**
    * Stopwords
      * Estamos planificando una logica de eliminacion de stopwords, donde se sigue una secuencia de pasos mediante un framework que internamente lo llamamos WordProcessor
    * Stemming
      * Se estima que se va a usar expresiones regulares para la deteccion de patrones en las palabras