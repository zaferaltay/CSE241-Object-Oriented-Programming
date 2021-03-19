import java.lang.reflect.Array;
import java.util.Arrays;

/**
 * @author zafer
 *
 * @param <T>
 */
public class GTUVector<T> extends GTUContainer<T> {
	
	/**
	 * i will serve as iterator
	 */
	GTUIterator<T> i;
	/**
	 * 
	 *  []data will allow us to keep the data
	 */
	public T []data;
	/**
	 * [] data2 inside the insert function will help to copy the data if maxsize is exceeded
	 */
	public T []data2;
	int maxsize=50;
	int current =0,counter=0;
	
	/**
	 * Constructor 
	 */
	public GTUVector (){
		data= (T[])new Object[maxsize];
	}
	/**
	 * Returns true if vector is empty
	 */
	public boolean empty(){
		if(current==0)
		return true;
		return false;
	}
	/**
	 * Returns vector size
	 */
	public int size() {
		return current;
	}
	/**
	 * Returns mexsize of vector
	 */
	public int maxSize() {
		return maxsize;
	}
	/**
	 * resets the vector
	 */
	public void clear() {
		maxsize=50;
		current=0;
		counter=0;
		data=(T[])new Object[maxsize];
	}
	public T get(int num) {
		return data[num];
	}
	/**
	 * Adds num1 into the vector.
	 * Increases size if max
	 * @param num1
	 */
	public void insert(T num1) {
		if(current==maxsize) {
			maxsize*=2;
			 T[] data2 = (T[]) Array.newInstance(data[0].getClass(), data.length * 2);
			 System.arraycopy(data, 0, data2, 0, data.length);
			 data=data2;
		}
			data[current]=num1;
			current++;
			
	}
	/**
	 * Deletes if num2 exists
	 * @param num2
	 */
	public void erase(T num2) {
		for(int i=0;i<current;i++) {
			if(num2==data[i]) {
				counter=i;
				break;
			}
		}
		for(int j=counter;j<current;j++) {
			data[j]=data[j+1];
		}
	}
	/**
	 * It takes abstract class obj and creates iterator
	 *@param obj
	 *@return
	 */
	public GTUIterator<T> Iterator(GTUContainer<T> obj){
		i=new GTUIterator<T>(obj); 
		return i;
	}

	public int getMaxsize() {
		return maxsize;
	}
	public void setMaxsize(int maxsize) {
		this.maxsize = maxsize;
	}
	public int getCurrent() {
		return current;
	}
	public void setCurrent(int current) {
		this.current = current;
	}
	@Override
	public String toString() {
		return "GTUVector [i=" + i + ", data=" + Arrays.toString(data) + ", maxsize=" + maxsize + ", current=" + current
				+ ", counter=" + counter + "]";
	}



}
