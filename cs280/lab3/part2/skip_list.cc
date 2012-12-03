//Charles Treatman ctreatma
//skip_list.cc

#include "skip_list.h"
#include "random_fun.h"
#include <iostream>

SkipList::SkipList(){
  sentinel = new SkipNode((Type) 0, NULL, NULL);
  maxHeight = 1;
  list_size = 0;
}

SkipList::SkipList(const SkipList& L){
  sentinel = new SkipNode((Type) 0, NULL, NULL);
  maxHeight = 1;
  list_size = 0;
  Type* arr = L.array();
  int size = L.size();
  for(int i = (size-1); i >= 0; --i){
    this->insert(arr[i]);
  }
  delete [] arr;
}


SkipList::~SkipList(){
  this->clear(); 
  delete sentinel;
} 
  
int SkipList::size() const{
  return list_size;
}

bool SkipList::empty() const{
  return (list_size == 0);
}

bool SkipList:: member(const Type& e) const{ 
  SkipNode * pred = getPredecessor(e);
  return (pred->hasRight() && pred->getRight()->getInfo() == e);
}

SkipNode* SkipList:: getPredecessor(const Type& e) const{
  SkipNode* current = sentinel;
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

void SkipList:: insert(const Type& e){

  using std::cout;

  bool success=false;
  int height = 1;
  while(coin_flip())
    height++;

  //increase sentinel height
  SkipNode* temp;
  for(int i = maxHeight; i < (height + 1); ++i){
    temp = new SkipNode(sentinel->getInfo(), NULL, sentinel);
    sentinel = temp;
  }
  maxHeight = (maxHeight > height)? maxHeight : height + 1;

  //construct the insertion tower
  temp = NULL;
  SkipNode* value = NULL;
  for(int i=0; i<height; ++i){
    temp = new SkipNode(e, NULL, value);
    value = temp;
  }
  //find the insertion height
  SkipNode* current = sentinel;
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

void SkipList::clear(){

  using std::cout;
  SkipNode* current = sentinel->getBottom();
  SkipNode* c2 = NULL;
  SkipNode* c3 = NULL;
  
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

Type* SkipList::array() const{
  Type* arr = new Type[list_size];
  
  SkipNode * current = sentinel;
  while(current->hasBottom())
    current = current->getBottom();
  
  for(int i=0; current->hasRight(); ++i){
    arr[i] = current->getRight()->getInfo();
    current = current->getRight();
  }
  return arr;
}

void SkipList::remove(const Type& e){
  using std:: cout;

  SkipNode* result = sentinel->getBottom();
  SkipNode* holder = result->getRight();
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
	SkipNode* temp = holder;
	holder = holder->getBottom();
	delete temp;
      }
    }
    result = result->getBottom();
  }
  if(success)  list_size--;
}


SkipList& SkipList::operator=(const SkipList& L){
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

bool SkipList::operator==(const SkipList& L) const {
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

int SkipList::countBlocks() const{
  SkipNode* current = sentinel;
  SkipNode* p = NULL;
  int count = 0;

  while(current){
    p = current->getRight();
    while(p && p->hasRight()){
      p = p->getRight();
      ++count;
    }
    current = current->getBottom();
    ++count;
  }

  return count;
}

int SkipList::countAccesses() const {
 SkipNode* current = sentinel;
 SkipNode* p = NULL;
  int count = 0;

  while(current){
    p = current->getRight();
    while(p && p->hasRight()){
      count += p->numAccesses();
      p = p->getRight();
    }
    current = current->getBottom();
    if(current)
      count +=current->numAccesses();
  }
  
  return count;
}

ostream& operator<<(ostream& sout, const SkipList& L) {
  SkipNode* current = L.sentinel;
  int i;

  while (current->getBottom() != NULL) {
    current = current->getBottom();
  }

  if (!L.empty()) {
    for (i = 0; i < L.size(); ++i) {
      if (i < L.size() - 1) {
	current = current->getRight();
	sout << current->getInfo() << " ";
      }
      else
	sout << current->getRight()->getInfo();
    }
  }

  return sout;
}
