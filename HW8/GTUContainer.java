
/**
 * @author zafer
 *
 * @param <T>
 */
public abstract class GTUContainer<T>{
	
	public abstract boolean empty();
	public abstract int size();
	public abstract int maxSize();
	public abstract void clear();
	public abstract void insert(T num1);
	public abstract void erase(T num2);
	public abstract GTUIterator<T> Iterator(GTUContainer<T> obj);
}
