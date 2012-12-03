// skip_node.h

#include <iostream>

#ifndef CS280_SKIP_NODE_H
#define CS280_SKIP_NODE_H

using std::ostream;
#define Type int

class SkipNode {
public:
  // Constructors
  SkipNode(Type e);
  SkipNode(Type e, SkipNode* right, SkipNode* bottom);
  SkipNode(const SkipNode& n);
  ~SkipNode();

  // Inspectors
  Type getInfo() const;
  bool hasRight() const;
  bool hasBottom() const;
  SkipNode* getRight() const;
  SkipNode* getBottom() const;
  int numAccesses() const;

  // Mutators
  void setInfo(Type e);
  void setRight(SkipNode* right);
  void setBottom(SkipNode* bottom);

  // Operators
  SkipNode& operator=(const SkipNode& n);
  bool operator==(const SkipNode& n);

private:
  Type info;
  SkipNode* right;
  SkipNode* bottom;

  int* num_accesses;
};

ostream& operator<<(ostream& sout, const SkipNode& p);
ostream& operator<<(ostream& sout, SkipNode* p);

#endif
