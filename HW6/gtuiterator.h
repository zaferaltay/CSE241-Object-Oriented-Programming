#ifndef GTUITERATOR_H_
#define GTUITERATOR_H_
#include<iostream>
#include <memory>
using namespace std;

namespace zaff{
template <class T>
class Node{
 public:
	Node(T data1,Node<T>* link):data(data1),next(link){};
	shared_ptr <Node<T>> getNext()const{return next;};
	const T& getData()const{return data;};
	void setData(const T& data1){data=data1;};
	void setNext(shared_ptr<Node<T>> link){next=link;};

 private:
	T data;
	shared_ptr <Node<T>> next;
};

template<class T>
class GTUIterator{
 public:
	GTUIterator();
	GTUIterator(shared_ptr<Node<T>> initial);
	const T& operator *()const;
	GTUIterator<T>& operator ++();
	GTUIterator<T>& operator --();
	const T& operator ->()const;
	void operator =(T data);
	bool operator ==(const GTUIterator<T>& other);
	bool operator !=(const GTUIterator<T>& other);
 private:
	shared_ptr<Node<T>> current;
};
}
#endif
