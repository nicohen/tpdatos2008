package bplus.keys;

public interface BPlusKey<E> {
	public E getValue();
	public void setValue(E element);
}
