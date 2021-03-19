#include "gtuvector.cpp"
#include "gtuset.cpp"

using namespace zaff;
//-----------------------------------------------------------------------------------------
template<class GTUIterator, class T>
GTUIterator find (GTUIterator first, GTUIterator last, const T& val)  //FIND FUNCTION
{
  while (first!=last) {
    if (*first==val) return first;
    ++first;
  }
  return last;
}
//-----------------------------------------------------------------------------------------------
template<class GTUIterator, class SmallerZero>
  GTUIterator find_if (GTUIterator first, GTUIterator last, SmallerZero pred)   //FIND IF
{
  while (first!=last) {
    if (pred(*first)) return first;
    ++first;
  }
  return last;
}
//------------------------------------------------------------------------------------------------------------
template<class GTUIterator, class Function>
  Function for_each(GTUIterator first, GTUIterator last, Function fn)		//FOR EACH
{
  while (first!=last) {
    fn (*first);
    ++first;
  }
  return fn;
}
//-------------------------------------------------------------------------------------------------
bool testFindIf(int x){ // I created for test vector
	if(x<0){
		return true;
	}
	else {
		return false;
	}
}
bool testFindIf2(double x){	//I created for test set
	if(x<0){
		return true;
	}
	else {
		return false;
	}	
}
void testForEach (int i) {  // I created for test vector
  cout << ' ' << i;
}
void testForEach2(double i){//I created for test set
	 cout << ' ' << i;
}


//-----------------------------------------------------------------------
int main(){


int choice;
	while(choice!=0){
		cout<<endl<<endl<<endl;
		cout<<"Which one do you want to test"<<endl;
		cout<<"1-)Vector"<<endl<<"2-)Set"<<endl<<"0-)Exit"<<endl;
		cin>>choice;

		if (choice==1)
		{
			GTUVector<int> v;
			cout<<"Firstly we have created int type vector"<<endl;
			cout<<"And we're filling in random numbers(10-20-30-40) with insert"<<endl<<endl;
			v.insert(10);v.insert(20);v.insert(30);v.insert(40);
			cout<<"And we're printing the screen using [] operator"<<endl;
			cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl<<endl;
			cout<<"Now we learn the size using the x function(It should be 4)"<<endl;
			cout<<"Vector size ="<<v.size()<<endl<<endl;
			cout<<"Now we're printing the vector using iterator(Now we will use *,++,!=operators in iterator)"<<endl;
				GTUVector<int>::Iterator i;
				for (i=v.begin(); i != v.end(); ++i)
					{
						cout<<*i<<" " ;
					}
			cout<<endl;
			cout<<"Now we testing = operator of iterator we will fill all elements with 100 and printing"<<endl;
				for (i=v.begin(); i != v.end(); ++i)
				{
					i=100;
				}
				for (i=v.begin(); i != v.end(); ++i)
					{
						cout<<*i<<" " ;
					}
			cout<<endl<<endl;
			cout<<"now reinstating the vector"<<endl;
			v.clear();v.insert(10);v.insert(20);v.insert(30);v.insert(40);							
			cout<<"Now we're erase a data using erase function"<<endl;
			v.erase(20);
			cout<<"we're printing again after erase(It should be 10 30 40)"<<endl;
				for (i=v.begin(); i != v.end(); ++i)
					{
						cout<<*i<<" " ;
					}
			cout<<endl<<endl;
			v.insert(-10);
			v.insert(80);
			cout<<"We insert again -10 and 80"<<endl;
			cout<<"we inserted -10 for testfindif function because it return the number that smaller than 0"<<endl<<endl;
			cout<<"we're testing find if functioon now"<<endl;
			i=find_if(v.begin(),v.end(),testFindIf);
			cout << "The first value smaller then zero is " << *i << '\n'<<endl;

			cout<<"We're printing all elements in vector using and testing for each function(we use testForEach)"<<endl;
			for_each (v.begin(), v.end(), testForEach);
			cout<<endl<<endl;

			cout<<"Now we test find function(we are looking for -10)"<<endl;
			cout<<"if the test is successful, it will display okey.(else will display unsuccesful)"<<endl<<endl;	
				if (i!=v.end())
				{
					cout<<"OKEYY"<<endl<<endl;
				}
				else{
					cout<<"UNSECCESFULL"<<endl;
				}
			cout<<"Now we're clear all data"<<endl;
			v.clear();
			cout<<"Now we insert only one number(99) and printing all data if it will printing only 99 it was successful(clear)"<<endl;
			v.insert(99);
			for_each (v.begin(), v.end(), testForEach);
			cout<<endl<<endl;
			cout<<"We now creating new char vector using GTUVector(int) constructor "<<endl;
			GTUVector<char> z(50);
			cout<<"And now we test max size(it should be 50)"<<endl;
			cout<<"Max size="<<z.maxsize()<<endl;

		}
		else if(choice==2){
			GTUSet<double> v;
			cout<<"Firstly we have created double type Set"<<endl;
			cout<<"And we're filling in random numbers(10.5 20.5 30.5 40.5) with insert"<<endl<<endl;
			v.insert(10.5);v.insert(20.5);v.insert(30.5);v.insert(40.5);
			cout<<"And we're printing the screen using iterator(Now we will use *,++,!=, operators in iterator)"<<endl;
				GTUSet<double>::Iterator i;
				for (i=v.begin(); i != v.end(); ++i)
				{
					cout<<*i<<endl;
				}

			cout<<"Now we learn the size using the x function(It should be 4)"<<endl;
			cout<<"Set size ="<<v.size()<<endl<<endl;
			cout<<"Now we're testing add elements again into set(20.5 and 50.5)"<<endl;
			cout<<"if it does not rewrite 20.5 ,it is succesfull"<<endl;
				v.insert(20.5);v.insert(50.5);
				for (i=v.begin(); i != v.end(); ++i)
					{
						cout<<*i<<" " ;
					}

			cout<<endl<<endl<<endl;

			cout<<"Now we're erase a data using erase function"<<endl;
			v.erase(30.5);
			cout<<"we're printing again after erase(It should be 10.5 20.5 40.5 50.5)"<<endl;
				for (i=v.begin(); i != v.end(); ++i)
					{
						cout<<*i<<" " ;
					}
			cout<<endl<<endl;
			v.insert(-10.5);
			v.insert(80.5);
			cout<<"We insert again -10.5 and 80.5"<<endl;
			cout<<"we inserted -10.5 for testfindif function because it return the number that smaller than 0"<<endl<<endl;
			cout<<"we're testing find if functioon now"<<endl;
			i=find_if(v.begin(),v.end(),testFindIf2);
			cout << "The first value smaller then zero is " << *i << '\n'<<endl;

			cout<<"We're printing all elements in vector using and testing for each function(we use testForEach)"<<endl;
			for_each (v.begin(), v.end(), testForEach2);
			cout<<endl<<endl;

			cout<<"Now we test find function(we are looking for -10.5)"<<endl;
			cout<<"if the test is successful, it will display okey.(else will display unsuccesful)"<<endl<<endl;	
				GTUSet<double>::Iterator j;
				j=find(v.begin(),v.end(),20.5);
				if (j!=v.end())
				{
					cout<<"OKEYY"<<endl<<endl;
				}
				else{
					cout<<"UNSECCESFULL"<<endl;
				}
			cout<<"Now we're clear all data"<<endl;
			v.clear();
			cout<<"Now we insert only one number(99.5) and printing all data if it will printing only 99.5 it was successful(clear)"<<endl;
			v.insert(99.5);
			for_each (v.begin(), v.end(), testForEach2);
			cout<<endl<<endl;
			cout<<"We now creating new int set using GTUSet(int) constructor "<<endl;
			GTUSet<int> z(50);
			cout<<"And now we test max size(it should be 50)"<<endl;
			cout<<"Max size="<<z.maxsize()<<endl;			
		}
	}

}