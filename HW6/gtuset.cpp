#include "gtuset.h"

namespace zaff{
template<class T>
GTUSet<T>::GTUSet():head(NULL),now(NULL){

}
template<class T>
GTUSet<T>::GTUSet(const GTUSet<T>& set){
	if(set.empty()){
		head=now=NULL;
	}
}
template<class T>
GTUSet<T>::~GTUSet(){
	head=NULL;
}
template<class T>
GTUSet<T>::GTUSet(int x){
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
bool GTUSet<T>::empty()const{
	if (head==NULL)
	{
		return true;
	}
	else{
		return false;
	}
}

template<class T>
GTUIterator<T> GTUSet<T>::begin()const{
	return Iterator(head);
}


template<class T>
void GTUSet<T>::clear(){
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
GTUIterator<T> GTUSet<T>::end()const{
	return Iterator(now->getNext());
}

template<class T>
T GTUSet<T>::operator[](int x){
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
int GTUSet<T>::maxsize(){
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
void GTUSet<T>::insert(T data){
	int flag=0;
	if (empty())
	{
		now=shared_ptr <Node<T>> (new Node<T> (data,NULL));
		head=now;
	}
	else{
		shared_ptr <Node<T>> temp;
		shared_ptr <Node<T>> temp2;
		temp=head;
		while(temp!=NULL){	
			if (data == temp->getData())
			{	
				flag=1;
				break;
			}
				temp=temp->getNext();
		  }	 
		if (flag==0)
		{
			temp2=shared_ptr <Node<T>> (new Node<T> (data,NULL));
			now->setNext(temp2);
			now=now->getNext();
		}
	}

}

template<class T>
void GTUSet<T>::erase(T data){
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
int GTUSet<T>::size(){
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