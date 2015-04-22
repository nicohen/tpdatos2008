Recientemente agregue varias clases para llevar estadisticas de bytes escritos y leidos

Para usarlo tiene que indica el "inicio" el "fin" de la operacion, ej:


```

    StatisticsGeneratorSingleton.get().init();

    /*
      ... codigo que ejecuta la query, etc...

    */
    Statistics stats = StatisticsGeneratorSingleton.get().finish();

    /*

       ... Imprimir las estadisticas, etc... ....
    */

    System.out.println (" Se leyeron " + stats.getReadedBytes() + " para resolver la consulta " );

```