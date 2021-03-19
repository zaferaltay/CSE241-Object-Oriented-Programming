
/**
 * @author zafer
 *
 * @param <T>
 */
public class GTUIterator <T>{
	
	public T []array;
	int current=0;
	int size;
	
	/**
	 * the object casts from the vector class to the vector or casts set
	 * @param obj
	 */
	GTUIterator(GTUContainer<T> obj){
			if(obj instanceof GTUVector) {
				GTUVector<T> obj1=(GTUVector<T>)obj;
				array=obj1.data;
				size=obj1.current;
			}
			else {
				GTUSet<T> obj1=(GTUSet<T>)obj;
				array=obj1.data;
				size=obj1.current;
			}
	}
	
	
	/**
	 * Iterator moves to the next element
	 * @return
	 */
	@SuppressWarnings("unchecked")
	public T next() { 
		return (T) array[current++];
	}

	/**
	 * If next element exist,returns true 
	 * @return true or false
	 */
	public boolean hasNext() {
		if(array[current]!=null) {
			return true;
		}
		return false;
	}
}