import java.util.Scanner;

/**
 * @author zafer
 *
 */
public class TestAll {

	public static void main(String []args) {
		
		int choice=0;
		Scanner x=new Scanner(System.in);
		System.out.println("Which would you like to test ? \n 1-) Vector 2-)Set");
		choice=x.nextInt();
		
		if(choice==1) {
			GTUVector<Integer> v= new GTUVector<Integer>();
			System.out.println("Firstly we have created int type vector");
			System.out.println("And we're filling in random numbers(10-20-30-40) with insert");
			v.insert(10);
			v.insert(20);
			v.insert(30);
			v.insert(40);
			System.out.println("Now we learn the size using the size function(It should be 4))");
			System.out.printf("Vector size= %d\n\n",v.size());
			System.out.println("Now we're printing the vector using iterator");
			GTUIterator<Integer> it=v.Iterator(v);
			System.out.println("Now we create an iterator for the vectors and test next and hasNext method");
			while(it.hasNext()) {
				System.out.printf("%d ",it.next());
			}
			System.out.println("\n");
			System.out.println("now reinstating the vector");
			v.clear();v.insert(10);v.insert(20);v.insert(30);v.insert(40);
			System.out.println("Now we're erase a data using erase function");
			v.erase(20);
			System.out.println("we're printing again after erase(It should be 10 30 40)");
			GTUIterator<Integer> it2=v.Iterator(v);
			while(it2.hasNext()) {
				System.out.printf("%d ",it2.next());
			}
			System.out.println("\nWe now creating new double vector using GTUVector constructor ");
			GTUVector<Double> z= new GTUVector<Double>();
			System.out.println("And now we test max size(it should be 50)");
			System.out.printf("Max size= %d",z.maxSize());
		}
		else if(choice==2) {
			GTUSet<Double> v= new GTUSet<Double>();
			System.out.println("Firstly we have created double type vector");
			System.out.println("And we're filling in random numbers(10.5-20.5-30.5-40.5) with insert");
			v.insert(10.5);
			v.insert(20.5);
			v.insert(30.5);
			v.insert(40.5);
			System.out.println("Now we learn the size using the size function(It should be 4))");
			System.out.printf("Vector size= %d\n\n",v.size());
			System.out.println("Now we're printing the vector using iterator");
			GTUIterator<Double> it=v.Iterator(v);
			System.out.println("Now we create an iterator for the vectors and test next and hasNext method");
			while(it.hasNext()) {
				System.out.printf("%.2f\n",it.next());
			}
			System.out.println("\n");
			System.out.println("now reinstating the vector");
			v.clear();v.insert(10.5);v.insert(20.5);v.insert(30.5);v.insert(40.5);
			System.out.println("Now we're erase a data using erase function");
			v.erase(10.5);
			System.out.println("we're printing again after erase(It should be 20.5 30.5 40.5)");
			GTUIterator<Double> it2=v.Iterator(v);
			while(it2.hasNext()) {
				System.out.printf("%.2f\n",it2.next());
			}
			System.out.println("\nWe now creating new character vector using GTUVector constructor ");
			GTUVector<Character> z= new GTUVector<Character>();
			System.out.println("And now we test max size(it should be 50)");
			System.out.printf("Max size= %d",z.maxSize());			
			
		}


	}
}
