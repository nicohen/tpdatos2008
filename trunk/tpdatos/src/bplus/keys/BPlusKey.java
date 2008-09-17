package bplus.keys;

public abstract class BPlusKey<E>  implements Comparable<BPlusKey>{
	public abstract E getValue();
	public abstract void setValue(E element);
	public abstract int getSize();
	public abstract int compareTo(BPlusKey element);
}
