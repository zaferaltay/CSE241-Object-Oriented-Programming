#ifndef GTUCONSTITERATOR_H_
#define GTUCONSTITERATOR_H_
#include<iostream>
#include"gtuiterator.h"
using namespace std;

namespace zaff{

template<class T>
class GTUConstIterator{
 public:
	GTUConstIterator();
	GTUConstIterator(shared_ptr<Node<T>> initial);
	const T& operator *()const;
	GTUConstIterator<T>& operator ++();
	GTUConstIterator<T>& operator --();
	const T& operator ->()const;
	bool operator ==(const GTUConstIterator<T>& other);
	bool operator !=(const GTUConstIterator<T>& other);
 private:
	shared_ptr<Node<T>> current;
};
}
#endif
