//Charles Treatman ctreatma
//skip_list.h

#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include "skip_node.h"
#include "sorted_list.h"

using std::ostream;

class SkipList : public SortedList
{
 public:
  //Constructors & Destructors
  SkipList();
  SkipList(const SkipList& L);
  virtual ~SkipList();

  //Inspectors
  virtual int size() const;
  virtual bool empty() const;
  virtual bool member(const Type& e) const;
  virtual Type* array() const;

  //Mutators
  virtual void insert(const Type& e);
  virtual void remove(const Type& e);
  virtual void clear();

  //Analysis Functions
  virtual int countBlocks() const;
  virtual int countAccesses() const;

  //Operators
  SkipList& operator=(const SkipList& L);
  bool operator==(const SkipList& L) const;

 private:
  SkipNode* sentinel;
  int list_size;
  int maxHeight;
  virtual SkipNode* getPredecessor(const Type& e) const;

  friend ostream& operator<<(ostream&, const SkipList&);
};

ostream& operator<<(ostream& sout, const SkipList& L);

#endif
