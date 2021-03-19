#include "gtuconstiterator.h"
namespace zaff{
template<class T>
GTUConstIterator<T>::GTUConstIterator():current(NULL){};

template<class T>
GTUConstIterator<T>::GTUConstIterator(shared_ptr<Node<T>>initial):current(initial){};

template<class T>
const T& GTUConstIterator<T>::operator *() const{
	return current->getData();
}

template<class T>
GTUConstIterator<T>& GTUConstIterator<T>::operator ++(){
	current=current->getNext();
	return *this;
}
template<class T>
const T& GTUConstIterator<T>::operator ->()const
{
	return current->getData();	
}

template<class T>
bool GTUConstIterator<T>::operator ==(const GTUConstIterator<T>& other){
	return (other.current==current);
}

template<class T>
bool GTUConstIterator<T>::operator!= (const GTUConstIterator<T>& other){
	return (other.current != current);
}
}