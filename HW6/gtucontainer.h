#ifndef GTUCONTAINER_H_
#define GTUCONTAINER_H_
#include "gtuiterator.cpp"
#include "gtuiterator.h"
#include "gtuconstiterator.cpp"
#include "gtuconstiterator.h"
namespace zaff{
template<class T>		
class GTUContainer{

	public:
		typedef GTUIterator<T> Iterator;
		virtual bool empty()const=0;
		virtual int size()=0;
		virtual int maxsize()=0;
		virtual void clear()=0;
		virtual Iterator begin()const=0;
		virtual Iterator end()const=0;
		virtual void insert(T data)=0;
		virtual void erase(T data)=0;
		
};
}
#endif
