import java.lang.reflect.Array;

/**
 * @author zafer
 *
 * @param <T>
 */
public class GTUSet<T> extends GTUContainer<T> {

	GTUIterator<T> i;
	public T []data;
	public T []data2;
	int maxsize=50;
	int current =0,counter=0;
	int flag=1;

	/**
	 * Returns max size
	 * @return
	 */
	public int getMaxsize() {
		return maxsize;
	}
	/**
	 * Returns current
	 * @return
	 */
	public int getCurrent() {
		return current;
	}
	/**
	 * Constructor
	 */
	public GTUSet (){
		data= (T[])new Object[maxsize];
	}
	/**
	 *If set is empty,return true
	 */
	public boolean empty(){
		if(current==0)
		return true;
		return false;
	}
	/**
	 * Returns size
	 * @return size
	 */
	public int size() {
		return current;
	}
	/**Returns max size
	 *@return max size
	 */
	public int maxSize() {
		return maxsize;
	}
	/**
	 *resets the set
	 */
	public void clear() {
		maxsize=50;
		current=0;
		counter=0;
		data=(T[])new Object[maxsize];
	}
	/**
	 * Returns numth index of set
	 * @param num
	 * @return
	 */
	public T get(int num) { 
		return data[num];
	}
	/**
	 *	Inserts num1 if not same element in set
	 *@param num1
	 *
	 *
	 */
	public void insert(T num1) {
		
		if(current==maxsize) {
			maxsize*=2;
			 T[] data2 = (T[]) Array.newInstance(data[0].getClass(), data.length * 2);
			 System.arraycopy(data, 0, data2, 0, data.length);
			 data=data2;
		}
		
		for(int i=0;i<current;i++) {
			if(num1==data[i]) {
				flag=0;
			}
		}
		if(flag==1) {
			data[current]=num1;
			current++;
			
		}
			
	}
	/**
	 *Deletes if num2 exists
	 *@param num2 
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
	 *@param obj abstract class object
	 *@return iterator
	 */
	public GTUIterator<T> Iterator(GTUContainer<T> obj){
		i=new GTUIterator<T>(obj); 
		return i;
	}
}
