# Organizacion de [tags y branches](Creacion_de_tags_y_branches.md) de proyecto #


## tags ##

> Vamos a crear un tags para cada entrega, incluyendo las pre-entregas (con esto se facilitaria la revision del proyecto si Mariana con la version que entregamos del codigo hace referencia a el ). No se descarta efectuar algunos otros tags, por ej, si alcazamos un nivel muy estable del proyecto que queremos conservar etiquetado o algo asi


## branches ##

> Podemos usar los branches para crear ramas del proyecto para dividir facilmente el trabajo de "establizar" el proyecto en una rama (corrigiendo bugs, etc...) y el trabajo de agregar mejoras en otra rama (generalmente lo hacen en el trunk )
> La operatoria consistiria, basicamente, en crear el branch algunos dias antes de la entrega definitiva, a apartir de creado el branch, dedicarse a testearlo a full e ir corrigiendolo. Mientras, si alguien quiere implementar alguna "mejora" (algunas modificaciones pueden estar sujetas a debate, si se consideran mejoras o no) sobre el proyecto , puede hacerlo en el trunk, por ende no se afecta la estabilidad del branch.
> Los parches y correcciones que se apliquen a una rama se pueden pasar facilmente al trunk gracias a la funcionalidad "merge"