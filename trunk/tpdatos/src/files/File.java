package files;

import java.io.IOException;

public interface File<E>{
	public int add(E element) throws IOException;
	public E get(int elementId) throws IOException;
	public int modify(int elementId, E newElement) throws IOException;
	public void remove(int elementId);
}
