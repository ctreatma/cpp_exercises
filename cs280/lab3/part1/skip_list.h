//Charles Treatman ctreatma
//skip_list.h

#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include "skip_node.h"

using std::ostream;

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

  //Analysis Functions
  int countBlocks();
  int countAccesses();

  //Operators
  SkipList& operator=(const SkipList& L);
  bool operator==(const SkipList& L) const;

 private:
  SkipNode* sentinel;
  int list_size;
  int maxHeight;
  SkipNode* getPredecessor(const Type& e) const;

  friend ostream& operator<<(ostream&, const SkipList&);
};

ostream& operator<<(ostream& sout, const SkipList& L);

#endif
