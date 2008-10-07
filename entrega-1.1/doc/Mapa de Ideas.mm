<map version="0.8.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1220720609046" ID="Freemind_Link_100004950" MODIFIED="1220721178156" TEXT="Sistema de Recuperacion de Textos Web">
<node CREATED="1220721189359" ID="_" MODIFIED="1220722191421" POSITION="right" TEXT="BrainStorming">
<icon BUILTIN="idea"/>
<node CREATED="1220724605151" ID="Freemind_Link_1118932332" MODIFIED="1220724639287" TEXT="Obtener el listsdo de nuevos documento"/>
<node CREATED="1220721203140" FOLDED="true" ID="Freemind_Link_341357117" MODIFIED="1220721311765" TEXT="Normalizar HTML">
<node CREATED="1220721233031" ID="Freemind_Link_860083259" MODIFIED="1220722160203" TEXT="Obtener el body">
<icon BUILTIN="full-1"/>
</node>
<node CREATED="1220721266984" ID="Freemind_Link_242521458" MODIFIED="1220722162093" TEXT="Eliminar los tags">
<icon BUILTIN="full-2"/>
</node>
<node CREATED="1220721361421" ID="Freemind_Link_1391403280" MODIFIED="1220722162703" TEXT="Decodificar los caracteres HTML (&amp;nbsp; &amp;eacute;)">
<icon BUILTIN="full-3"/>
</node>
</node>
<node CREATED="1220721388468" FOLDED="true" ID="Freemind_Link_1281968609" MODIFIED="1220721991265" TEXT="Reconocer los terminos">
<node CREATED="1220721403687" ID="Freemind_Link_1337465430" MODIFIED="1220722030500" TEXT="Eliminar signos ortograficos">
<icon BUILTIN="full-1"/>
<node CREATED="1220722031609" ID="Freemind_Link_1590989978" MODIFIED="1220722033484" TEXT="Acentos"/>
<node CREATED="1220722034546" ID="Freemind_Link_206041380" MODIFIED="1220722037031" TEXT="Dieresis"/>
</node>
<node CREATED="1220722054343" ID="Freemind_Link_1101241559" MODIFIED="1220722077703" TEXT="Sustituir mayusculas por minusculas (case folding)">
<icon BUILTIN="full-2"/>
</node>
<node CREATED="1220722109671" ID="Freemind_Link_1708326569" MODIFIED="1220722120640" TEXT="Eliminar palabras comunes (stopwords)">
<icon BUILTIN="full-3"/>
</node>
<node CREATED="1220721470828" ID="Freemind_Link_1740800756" MODIFIED="1220722151531" TEXT="Sustituir palabras por raices (Stemming)">
<icon BUILTIN="full-4"/>
</node>
<node CREATED="1220728478741" ID="Freemind_Link_226734025" MODIFIED="1220728650153" TEXT="Archivo con terminos encontrados">
<icon BUILTIN="full-5"/>
</node>
<node CREATED="1220725940611" ID="Freemind_Link_1456720146" MODIFIED="1220725953110" TEXT="Observaciones">
<node CREATED="1220725956188" ID="Freemind_Link_59604780" MODIFIED="1220725983904" TEXT="Recorrer el archivo una sola vez (procesamiento por palabra)"/>
<node CREATED="1220725986997" ID="Freemind_Link_1919006680" MODIFIED="1220726087533" TEXT="Usar el patron de encadenamiento de procesos  (TBD)"/>
<node CREATED="1220726443980" ID="Freemind_Link_1625531999" MODIFIED="1220727148651" TEXT="Se puede tomar steaming, case folding, acentos como casos de normalizacion (Normalizator)"/>
</node>
</node>
<node CREATED="1220721490593" FOLDED="true" ID="Freemind_Link_1222124852" MODIFIED="1220721612609" TEXT="Almacenar archivos de texto">
<node CREATED="1220722332921" ID="Freemind_Link_516103784" MODIFIED="1220722342812" TEXT="Estos archivos se almacenan completos"/>
<node CREATED="1220722351062" ID="Freemind_Link_365614622" MODIFIED="1220729084987" TEXT="Se debera registrar su entrada para poder recuperarlos (ID,TITLE,PATH)"/>
<node CREATED="1220729269024" ID="Freemind_Link_1036163458" MODIFIED="1220729296350" TEXT="Analizar, si hay que implementar la lista de documentos por distancia."/>
</node>
<node CREATED="1220721616671" FOLDED="true" ID="Freemind_Link_1648468212" MODIFIED="1220721629984" TEXT="Generar un indice de terminos">
<node CREATED="1220721709468" ID="Freemind_Link_650809376" MODIFIED="1220722431750" TEXT="Indice invertido (Almacenamiento en BTree)">
<node CREATED="1220722444546" ID="Freemind_Link_1467049913" MODIFIED="1220722450609" TEXT="Se permite modificar el tama&#xf1;o de los nodos"/>
</node>
<node CREATED="1220722393359" ID="Freemind_Link_162454928" MODIFIED="1220722410562" TEXT="Indice con archivos de firma (Signature Files)"/>
</node>
<node CREATED="1220721633796" ID="Freemind_Link_922373191" MODIFIED="1220721648218" STYLE="fork" TEXT="Resolver consultas de terminos en archivos procesados"/>
<node CREATED="1220721652812" FOLDED="true" ID="Freemind_Link_1778771550" MODIFIED="1220721657687" TEXT="Presentar resultados de busqueda">
<node CREATED="1220729386032" ID="Freemind_Link_569253639" MODIFIED="1220729449966" TEXT="tama&#xf1;o de la lista de docs. recuperados"/>
<node CREATED="1220729453747" ID="Freemind_Link_1249575223" MODIFIED="1220729457763" TEXT="tiempo de busqueda"/>
<node CREATED="1220729462122" ID="Freemind_Link_824412828" MODIFIED="1220729514885" TEXT="Cantidad de bytes leidos del disco"/>
</node>
<node CREATED="1220724659643" FOLDED="true" ID="Freemind_Link_1536688001" MODIFIED="1220731481875" TEXT="Dudas">
<icon BUILTIN="help"/>
<node CREATED="1220724703825" ID="Freemind_Link_180254460" MODIFIED="1220724722947" TEXT="&#xbf;el indice tiene que ser DINAMICO o ESTATICO?"/>
<node CREATED="1220724842384" ID="Freemind_Link_1098459954" MODIFIED="1220724863819" TEXT="&#xbf; Debe permitir la re-indexacion ?"/>
<node CREATED="1220727445079" ID="Freemind_Link_1114952103" MODIFIED="1220727464687" TEXT="&#xbf; Debe permitir la modificacion y eliminacion de documentos?"/>
</node>
</node>
<node CREATED="1220729723593" ID="Freemind_Link_162928351" MODIFIED="1220732610668" POSITION="left" TEXT="Estructuras alternativas">
<node CREATED="1220729844165" ID="Freemind_Link_791318269" MODIFIED="1220729849368" TEXT="Arbol B+"/>
<node CREATED="1220729852868" ID="Freemind_Link_1416101893" MODIFIED="1220732602293" TEXT="Archivo relativo (como diccionario)"/>
<node CREATED="1220730133806" ID="Freemind_Link_295815300" MODIFIED="1220730345952" TEXT="Encapsulamiento">
<node CREATED="1220730348108" ID="Freemind_Link_1803409644" MODIFIED="1220730357295" TEXT="Abstraer estructuras"/>
<node CREATED="1220730361998" ID="Freemind_Link_718106963" MODIFIED="1220730368060" TEXT="Separar estructuras del uso"/>
</node>
<node CREATED="1220731401050" ID="Freemind_Link_1724398734" MODIFIED="1220731478157" TEXT="Dudas">
<icon BUILTIN="help"/>
<node CREATED="1220732081434" ID="Freemind_Link_170489964" MODIFIED="1220732091340" TEXT="Que organizacion usar para cada archivo"/>
<node CREATED="1220733178060" ID="Freemind_Link_1941282415" MODIFIED="1220733188575" TEXT="Se persiste el index set en un arbol B+?"/>
</node>
</node>
<node CREATED="1220732139370" ID="Freemind_Link_1167783360" MODIFIED="1220732168588" POSITION="right" TEXT="Almacenamiento de Textos">
<node CREATED="1220732146073" ID="Freemind_Link_134471356" MODIFIED="1220732177134" TEXT="Almacenamiento de Terminos">
<node CREATED="1220732196680" ID="Freemind_Link_1107385813" MODIFIED="1220732207336" TEXT="Tries"/>
</node>
<node CREATED="1220732178540" ID="Freemind_Link_414208326" MODIFIED="1220732186525" TEXT="Vinculacion de terminos-documentos">
<node CREATED="1220732209805" ID="Freemind_Link_1325505224" MODIFIED="1220732215258" TEXT="BTree"/>
</node>
<node CREATED="1220732187931" ID="Freemind_Link_400829727" MODIFIED="1220732193993" TEXT="Almacenamiento de documentos">
<node CREATED="1220732216867" ID="Freemind_Link_1126271139" MODIFIED="1220732262991" TEXT="Secuencial"/>
</node>
<node CREATED="1220732243554" ID="Freemind_Link_661635914" MODIFIED="1220732245726" TEXT="Dudas">
<node CREATED="1220732246804" ID="Freemind_Link_1752206474" MODIFIED="1220732266553" TEXT="Consultar si esta bien la decision">
<icon BUILTIN="help"/>
</node>
</node>
</node>
</node>
</map>
