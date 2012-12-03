//link_node.h

#ifndef CS280_RLNODE_H
#define CS280_RLNODE_H

#include <iostream>

using std::ostream;
#define Type int

class LinkNode
{
   public:
      //Constructors
      LinkNode(Type e);
      LinkNode(Type e, LinkNode* next);
      LinkNode(const LinkNode& n);
      ~LinkNode();

      //Inspectors
      Type getInfo() const;
      bool hasNext() const;
      LinkNode* getNext() const;
      int numAccesses() const;
      
      //Mutators
      void setInfo(Type e);
      void setNext(LinkNode* node);
      
      //Operators
      LinkNode& operator=(const LinkNode& n);
      bool operator==(const LinkNode& n);

   private:
      Type info;
      LinkNode* next;

      int* num_accesses;
};

ostream& operator<<(ostream& sout, const LinkNode& p);
ostream& operator<<(ostream& sout, LinkNode* p);

#endif
