// skip_list_node.cc
#include <stdlib.h>
#include "skip_node.h"

SkipNode::SkipNode(Type e) {
  info = e;
  right = NULL;
  bottom = NULL;
  num_accesses = new int[1];
  *num_accesses = 0;
}

SkipNode::SkipNode(Type e, SkipNode* right, SkipNode* bottom) {
  info = e;
  this->right = right;
  this->bottom = bottom;
  num_accesses = new int[1];
  *num_accesses = 0;
}

SkipNode::SkipNode(const SkipNode& n) {
  info = n.getInfo();
  right = NULL;
  bottom = NULL;
  num_accesses = new int[1];
  *num_accesses = 0;
}

SkipNode::~SkipNode() {
  delete num_accesses;
}

Type SkipNode::getInfo() const {
  (*num_accesses)++;
  return info;
}

bool SkipNode::hasRight() const {
  return right != NULL;
}

bool SkipNode::hasBottom() const {
  return bottom != NULL;
}

SkipNode* SkipNode::getRight() const {
  return right;
}

SkipNode* SkipNode::getBottom() const {
  return bottom;
}

void SkipNode::setInfo(Type e) {
  info = e;
}

void SkipNode::setRight(SkipNode* right) {
  this->right = right;
}

void SkipNode::setBottom(SkipNode* bottom) {
  this->bottom = bottom;
}

int SkipNode::numAccesses() const {
  return *num_accesses;
}

SkipNode& SkipNode::operator=(const SkipNode& n) {
  if (this != &n) {
    info = n.getInfo();
  }

  return *this;
}

bool SkipNode::operator==(const SkipNode& n) {
  return (getInfo() == n.getInfo());
}

ostream& operator<<(ostream& sout, SkipNode p) {
  sout << &p;

  return sout;
}

ostream& operator<<(ostream& sout, SkipNode* p) {
  sout << p->getInfo();

  return sout;
}
