//Charles Treatman ctreatma
//skip_list.h

#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include "skip_node.h"

using std::ostream;

template <class Type>
class SkipList {
 public:
  //Constructors & Destructors
  SkipList();
  SkipList(const SkipList& L);
  ~SkipList();

  //Inspectors
  int size() const;
  bool empty() const;
  bool member(const Type& e) const;
  Type* array() const;

  //Mutators
  void insert(const Type& e);
  void remove(const Type& e);
  void clear();

  //Operators
  SkipList& operator=(const SkipList& L);
  bool operator==(const SkipList& L) const;

 private:
  SkipNode<Type>* sentinel;
  int list_size;
  int maxHeight;
  SkipNode<Type>* getPredecessor(const Type& e) const;
};

/*****************************************************************************/

//Charles Treatman ctreatma
//skip_list.cc

#include "random_fun.h"
#include <iostream>

template <class Type>
SkipList<Type>::SkipList(){
  sentinel = new SkipNode<Type>((Type) 0, NULL, NULL);
  maxHeight = 1;
  list_size = 0;
}

template <class Type>
SkipList<Type>::SkipList(const SkipList& L){
  sentinel = new SkipNode<Type>((Type) 0, NULL, NULL);
  maxHeight = 1;
  list_size = 0;
  Type* arr = L.array();
  int size = L.size();
  for(int i = (size-1); i >= 0; --i){
    this->insert(arr[i]);
  }
  delete [] arr;
}

template <class Type>
SkipList<Type>::~SkipList(){
  this->clear(); 
  delete sentinel;
} 
  
template <class Type>
int SkipList<Type>::size() const{
  return list_size;
}

template <class Type>
bool SkipList<Type>::empty() const{
  return (list_size == 0);
}

template <class Type>
bool SkipList<Type>::member(const Type& e) const{ 
  SkipNode<Type>* pred = getPredecessor(e);
  return (pred->hasRight() && pred->getRight()->getInfo() == e);
}

template <class Type>
SkipNode<Type>* SkipList<Type>::getPredecessor(const Type& e) const{
  SkipNode<Type>* current = sentinel;
  while(true){
    while(current->hasRight() && current->getRight()->getInfo() < e)
      current = current->getRight();   

    if(current->hasBottom()){
      current = current->getBottom();
      continue;
    }
    else
      return current;
  }
}

template <class Type>
void SkipList<Type>::insert(const Type& e){

  bool success=false;
  int height = 1;
  while(coin_flip())
    height++;

  //increase sentinel height
  SkipNode<Type>* temp;
  for(int i = maxHeight; i < (height + 1); ++i){
    temp = new SkipNode<Type>(sentinel->getInfo(), NULL, sentinel);
    sentinel = temp;
  }
  maxHeight = (maxHeight > height)? maxHeight : height + 1;

  //construct the insertion tower
  temp = NULL;
  SkipNode<Type>* value = NULL;
  for(int i=0; i<height; ++i){
    temp = new SkipNode<Type>(e, NULL, value);
    value = temp;
  }
  //find the insertion height
  SkipNode<Type>* current = sentinel;
  int j;
  for(j=maxHeight; j>height; --j){
    current=current->getBottom();
  }

  //find the insertion point
  for(int i = j; i > 0; --i){
    while(current->hasRight() && current->getRight()->getInfo() < e)
      current = current->getRight();
    //we must be in the right place now...
    value->setRight(current->getRight());
    current->setRight(value);
    success=true;
    value = value->getBottom();
    current = current->getBottom();
  }
  if(success)  
    list_size++;

}

template <class Type>
void SkipList<Type>::clear(){
  SkipNode<Type>* current = sentinel->getBottom();
  SkipNode<Type>* c2 = NULL;
  SkipNode<Type>* c3 = NULL;
  
  //clears each row of the skiplist
  while(current){
    c2= current->getRight();
    while(c2){
      c3 = c2;
      c2 = c2->getRight();
      delete c3;
    }
    c3 = current->getBottom();
    delete current;
    current = c3;
  }
  sentinel->setBottom(NULL);
  maxHeight = 1;
  list_size = 0;
}

template <class Type>
Type* SkipList<Type>::array() const{
  Type* arr = new Type[list_size];
  
  SkipNode<Type>* current = sentinel;
  while(current->hasBottom())
    current = current->getBottom();
  
  for(int i=0; current->hasRight(); ++i){
    arr[i] = current->getRight()->getInfo();
    current = current->getRight();
  }
  return arr;
}

template <class Type>
void SkipList<Type>::remove(const Type& e){
  SkipNode<Type>* result = sentinel->getBottom();
  SkipNode<Type>* holder = result->getRight();
  bool success=false;


  while(result != NULL){
    while(result->hasRight() && result->getRight()->getInfo() <e){
      result = result->getRight();
    }
    holder = result->getRight();
    if(holder != NULL){
      if(holder->getInfo() == e){	
	success=true;
	result->setRight(holder->getRight());
	SkipNode<Type>* temp = holder;
	holder = holder->getBottom();
	delete temp;
      }
    }
    result = result->getBottom();
  }
  if(success)
    list_size--;
}

template <class Type>
SkipList<Type>& SkipList<Type>::operator=(const SkipList<Type>& L){
  if(this != &L){
    this->clear();
    Type* arr = L.array();
    int size = L.size();
    for(int i=(size-1); i>=0; --i){
      this->insert(arr[i]);
    }
  delete arr;
  }
  return *this;
} 

template <class Type>
bool SkipList<Type>::operator==(const SkipList<Type>& L) const {
  int i;

  if (this != &L) {
    if (L.size() == list_size) {
      Type* arrL = L.array();
      Type* arrthis = this->array();
      for (i = 0; i < list_size; ++i) {
	if (arrL[i] != arrthis[i])
	  return false;
      }
      return true;
    }
    return false;
  }
  return true;
}

template <class Type>
ostream& operator<<(ostream& sout, const SkipList<Type>& L) {
  Type* arr = L.array();

  for (int i = 0; i < L.size(); ++i) {
    if (i < L.size() - 1)
      sout << arr[i] << " ";
    else
      sout << arr[i] << endl;
  }

  delete [] arr;
  return sout;
}


#endif
