#include "gtuvector.h"

namespace zaff{
template<class T>
GTUVector<T>::GTUVector():head(NULL),now(NULL){
}
template<class T>
GTUVector<T>::GTUVector(int x){
	int i=1;
	shared_ptr<Node<T>> temp=shared_ptr <Node<T>> (new Node<T> (0,NULL));
	now=head=temp;
	while(i<x){
	temp=shared_ptr <Node<T>> (new Node<T> (0,NULL));
	now->setNext(temp);
	now=now->getNext();

	i++;

	}
}
template<class T>
GTUVector<T>::GTUVector(const GTUVector<T>& vect){
	if(vect.empty()){
		head=now=NULL;
	}
}
template<class T>
GTUVector<T>::~GTUVector(){

	head=NULL;
}

template<class T>
int GTUVector<T>::maxsize(){
	int i=1;
	shared_ptr <Node<T>> temp;
	temp=head;
	while(temp->getNext()!=NULL){
		temp=temp->getNext();
		i++;
	}

	return i;	
}

template<class T>
bool GTUVector<T>::empty()const{
	if (head==NULL)
	{
		return true;
	}
	else{
		return false;
	}
}

template<class T>
GTUIterator<T> GTUVector<T>::begin()const{
	return Iterator(head);
}

template<class T>
GTUIterator<T> GTUVector<T>::end()const{
	return Iterator(now->getNext());
}

template<class T>
T GTUVector<T>::operator[](int x){
	int i=0;
	shared_ptr <Node<T>> temp;
	temp=head;
	while(i<x){
		temp=temp->getNext();
		i++;
	}
	return temp->getData();

}

template<class T>
void GTUVector<T>::insert(T data){
	if (empty())
	{
		now=shared_ptr <Node<T>> (new Node<T> (data,NULL));
		head=now;
		
	}
	else{
		shared_ptr <Node<T>> temp;
		temp=shared_ptr <Node<T>> (new Node<T> (data,NULL));
		now->setNext(temp);
		now=now->getNext();
	}

}

template<class T>
void GTUVector<T>::clear(){
	shared_ptr <Node<T>> temp;

while(temp!=head){

		temp=head;
		while(temp->getNext()->getNext()!=NULL){
			temp=temp->getNext();
		}
		temp->setNext(NULL);
	

	}
	head=NULL;
}


template<class T>
void GTUVector<T>::erase(T data){
	int i=0;
	shared_ptr <Node<T>> temp;
	shared_ptr <Node<T>> temp2;
	temp=head;
	while(temp->getNext()->getData()!=data){
		temp=temp->getNext();

	}
	temp2=temp->getNext()->getNext();
	temp->setNext(temp2);
}
template<class T>
int GTUVector<T>::size(){
	int i=1;
	shared_ptr <Node<T>> temp;
	temp=head;
	while(temp->getNext()!=NULL){
		temp=temp->getNext();
		i++;
	}

	return i;
}
}