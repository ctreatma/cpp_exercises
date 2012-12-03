//link_list.h

#ifndef CS280_LINKED_LIST_H
#define CS280_LINKED_LIST_H

#include "sorted_list.h"
#include "link_node.h"
#define Type int

class LinkList : public SortedList
{
   public:
      //Constructors
      LinkList();
      virtual ~LinkList();
      LinkList(const LinkList& lst);

      //Inspectors
      virtual int size() const;
      virtual bool empty() const;
      virtual bool member(const Type& e) const;
      virtual Type* array() const;
      virtual int countBlocks() const;
      virtual int countAccesses() const;

      //Mutators
      virtual void insert(const Type& e);
      virtual void remove(const Type& e);
      virtual void clear();

      //Operators
      LinkList& operator=(const LinkList& lst);
      bool operator==(const LinkList& lst) const;

   private:
      int mySize;
      LinkNode* head;      
};

ostream& operator<<(ostream& s, const LinkList& l);

#endif
