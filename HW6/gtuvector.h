#ifndef GTUVECTOR_H_
#define GTUVECTOR_H_
#include "gtucontainer.h"

namespace zaff{

template<class T>
class GTUVector:public GTUContainer<T>{
 public:
	GTUVector();
	GTUVector(int x);
	GTUVector(const GTUVector<T>& vect);
	virtual ~GTUVector();
	T operator[](int x);
	GTUVector<T>& operator =(GTUVector<T>& other);
		typedef GTUIterator<T> Iterator;
		virtual bool empty()const;
		virtual int size();
		virtual int maxsize();
		virtual void clear();
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
