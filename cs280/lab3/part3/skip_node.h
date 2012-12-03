// skip_node.h

#ifndef CS280_SKIP_NODE_H
#define CS280_SKIP_NODE_H

#include <iostream>

using std::ostream;

template <class Type>
class SkipNode {
public:
  // Constructors
  SkipNode(Type e);
  SkipNode(Type e, SkipNode<Type>* right, SkipNode<Type>* bottom);
  SkipNode(const SkipNode<Type>& n);
  ~SkipNode();

  // Inspectors
  Type getInfo() const;
  bool hasRight() const;
  bool hasBottom() const;
  SkipNode<Type>* getRight() const;
  SkipNode<Type>* getBottom() const;

  // Mutators
  void setInfo(Type e);
  void setRight(SkipNode<Type>* right);
  void setBottom(SkipNode<Type>* bottom);

  // Operators
  SkipNode& operator=(const SkipNode& n);
  bool operator==(const SkipNode& n);

private:
  Type info;
  SkipNode<Type>* right;
  SkipNode<Type>* bottom;
};

template <class Type>
ostream& operator<<(ostream& sout, const SkipNode<Type>& p);

template <class Type>
ostream& operator<<(ostream& sout, SkipNode<Type>* p);

//----------------------------------------------------------------
// skip_list_node.cc
#include <stdlib.h>

template <class Type>
SkipNode<Type>::SkipNode(Type e) {
  info = e;
  right = NULL;
  bottom = NULL;
}

template <class Type>
SkipNode<Type>::SkipNode(Type e, SkipNode<Type>* right, SkipNode<Type>* bottom) {
  info = e;
  this->right = right;
  this->bottom = bottom;
}

template <class Type>
SkipNode<Type>::SkipNode(const SkipNode<Type>& n) {
  info = n.getInfo();
  right = NULL;
  bottom = NULL;
  num_accesses = new int[1];
  *num_accesses = 0;
}

template <class Type>
SkipNode<Type>::~SkipNode() {
  // Nothing is done.
}

template <class Type>
Type SkipNode<Type>::getInfo() const {
  return info;
}

template <class Type>
bool SkipNode<Type>::hasRight() const {
  return right != NULL;
}

template <class Type>
bool SkipNode<Type>::hasBottom() const {
  return bottom != NULL;
}

template <class Type>
SkipNode<Type>* SkipNode<Type>::getRight() const {
  return right;
}

template <class Type>
SkipNode<Type>* SkipNode<Type>::getBottom() const {
  return bottom;
}

template <class Type>
void SkipNode<Type>::setInfo(Type e) {
  info = e;
}

template <class Type>
void SkipNode<Type>::setRight(SkipNode<Type>* right) {
  this->right = right;
}

template <class Type>
void SkipNode<Type>::setBottom(SkipNode<Type>* bottom) {
  this->bottom = bottom;
}

template<class Type>
ostream& operator<<(ostream& sout, SkipNode<Type> p) {
  sout << &p;

  return sout;
}

template<class Type>
ostream& operator<<(ostream& sout, SkipNode<Type>* p) {
  sout << p->getInfo();

  return sout;
}

template<class Type>
SkipNode<Type>& SkipNode<Type>::operator=(const SkipNode<Type>& n) {
  if (this != &n) {
    info = n.getInfo();
  }

  return *this;
}

template<class Type>
bool SkipNode<Type>::operator==(const SkipNode<Type>& n) {
  return (getInfo() == n.getInfo());
}
#endif
