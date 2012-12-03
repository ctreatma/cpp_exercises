//sorted_list.h

#ifndef CS280_SORTED_LIST_H
#define CS280_SORTED_LIST_H

#define Type int

class SortedList
{
   public:
      //Inspectors
      virtual int size() const = 0;
      virtual bool empty() const = 0;
      virtual bool member(const Type& e) const = 0;
      virtual Type* array() const = 0;
      virtual int countBlocks() const = 0;
      virtual int countAccesses() const = 0;

      //Mutators
      virtual void insert(const Type& e) = 0;
      virtual void remove(const Type& e) = 0;
      virtual void clear() = 0;
};

#endif
