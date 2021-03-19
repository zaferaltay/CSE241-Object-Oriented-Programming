#ifndef GTUSET_H_
#define GTUSET_H_
#include "gtucontainer.h"


namespace zaff{
template<class T>
class GTUSet:public GTUContainer<T>{
 public:
	GTUSet();
	GTUSet(int x);
	GTUSet(const GTUSet<T>& vect);
	virtual ~GTUSet();
	T operator[](int x);
	GTUSet<T>& operator =(GTUSet<T>& other);
		typedef GTUIterator<T> Iterator;
		virtual bool empty()const;
		virtual int size();
		virtual int maxsize();
		virtual void clear();
		void testForEach(int a);
		virtual Iterator begin()const;
		virtual Iterator end()const;
		virtual void insert(T data);
		virtual void erase(T data);
			
 private:
	shared_ptr <Node<T>> head;
	shared_ptr <Node<T>> now;		
};
}
#endif
