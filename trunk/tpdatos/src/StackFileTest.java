import junit.framework.TestCase;
import persistors.BytePersistor;
import exceptions.DataAccessException;
import files.StackFile;

public class StackFileTest extends TestCase{
	public void testPush() throws DataAccessException{
		BytePersistor persistor = new BytePersistor();
		StackFile<Byte> stack = new StackFile<Byte>("test_stack.bin",persistor);
		stack.push(new Byte((byte)16));
		stack.push(new Byte((byte)64));
		stack.push(new Byte((byte)100));
		assertEquals(stack.pop(),new Byte((byte)100));
		assertEquals(stack.pop(),new Byte((byte)64));
		assertEquals(stack.pop(),new Byte((byte)16));
		stack.push(new Byte((byte)16));
		stack.push(new Byte((byte)64));
		stack.push(new Byte((byte)512));
	}
}
