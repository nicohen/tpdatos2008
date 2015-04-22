Estuve leyendo lo ultio que se definio en el nodo del arbol b+

Esto es una parte de BPlusNode.java :

```

public interface BPlusNode {
	public void insertElement(BPlusElement element);
	public BPlusElement getElement(BPlusNodeKey nodeKey);
	public boolean isLeafNode();
	public Iterator<BPlusElement> getElementsIterator();
	public BPlusNodeKey getNodeKey();
}

```

El metodo "isLeafNode()" que retorna boolean, me llamo la atencion, retorna true en el caso del LeafNode :

...
```
	@Override
	public boolean isLeafNode() {
		return true;
	}
```

...

, y retorna false en el caso del IndexNode:


...
```
	@Override
	public boolean isLeafNode() {
		return false;
	}
```
...


> Esto es usar el polimorfismo para devolver informacion del tipo de dato..., capaz para tomar una decision en funcion de eso, una utilizacion demasiado simple del polimorfismo... A mi se me ocurren dos cosas que podriamos hacer:

a) Quitar el polimorfismo, que no se esta usando para la separacion entre Leaf nodes e Index node (es la que me parece mas practica y sencilla)

b) Buscar la manera de usar el polimorfismo de la forma mas provechosa posible (suena complejo)