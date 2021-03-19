#include "gtuiterator.h"
namespace zaff{

template<class T>
GTUIterator<T>::GTUIterator():current(NULL){};

template<class T>
GTUIterator<T>::GTUIterator(shared_ptr<Node <T>>initial):current(initial){};

template<class T>
const T& GTUIterator<T>::operator *() const{
	return current->getData();
}

template<class T>
GTUIterator<T>& GTUIterator<T>::operator ++(){
	current=current->getNext();
	return *this;
}

template<class T>
const T& GTUIterator<T>::operator ->()const
{
	return current->getData();	
}
template<class T>
void GTUIterator<T>::operator =(T data){
	current->setData(data);
}
template<class T>
bool GTUIterator<T>::operator ==(const GTUIterator<T>& other){
	return (other.current==current);
}

template<class T>
bool GTUIterator<T>::operator!= (const GTUIterator<T>& other){
	return (other.current != current);
}
}