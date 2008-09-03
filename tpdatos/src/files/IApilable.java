package files;

public interface IApilable<E> {
	public void push(E element) throws Exception;
	public E pop() throws Exception;

}
