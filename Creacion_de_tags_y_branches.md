# Metodos para crear tags del proyecto ( o tambien branches ) #

## Con tortoise svn ##

> Desde una ventana del explorer, hacer click con el boton derecho en la carpeta del proyecto, elegir la opcion "TortoiseSVN" del menu contextual, elegir la opcion Branch/Tag del sub-menu
> Va a aparecer un cuadro de dialogo, en donde se debe especificar la URL a donde se quiere crear el tag (o el branch), luego se da al OK ... y ,listo

## Por consola, desde linux ##

> Ejecutar el siguiente comando desde una shell

> svn cp 

&lt;url-origen&gt;

 

&lt;url-destino&gt;



> Ej:

> svn cp https://tpdatos2008.googlecode.com/svn/trunk/tpdatos https://tpdatos2008.googlecode.com/svn/tags/tpdatos-preentrega-1


> Tanto en el caso de que usen tortoise como en el caso de que lo  hagan desde linux, recuerde que deben checkautear el tag si quieren ver los resultados.
> Por favor si se dan cuenta que me olvide de explicar algo, agreguenlo