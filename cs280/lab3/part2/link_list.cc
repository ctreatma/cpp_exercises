//link_list.cc

#include "link_list.h"
#include "link_node.h"

#define Type int

LinkList::LinkList()
{
   mySize = 0;
}

LinkList::~LinkList()
{
   clear();
}

LinkList::LinkList(const LinkList& lst)
{
   Type* myArray = lst.array();

   for(int i = 0; i < lst.size(); i++)
   {
      insert(myArray[i]);
   }

   delete [] myArray;
}

int LinkList::size() const
{
   return mySize;
}

bool LinkList::empty() const
{
   return (mySize == 0);
}

bool LinkList::member(const Type& e) const
{
   LinkNode* counter = head;

   if(counter == NULL)
   {
      return false;
   }

   while(counter->hasNext())
   {
      if(counter->getInfo() == e)
      {
	 return true;
      }
      else if(e < counter->getInfo())
      {
	 return false;
      }
      else
      {
	 counter = counter->getNext();
      }
   }

   if(counter->getInfo() == e)
   {
      return true;
   }
   else
   {
      return false;
   }
}

Type* LinkList::array() const
{
   Type* myArray = new Type[mySize];
   
   LinkNode* counter = head;

   int currentSize = mySize;

   for(int i = 0; i < currentSize; i++)
   {
      myArray[i] = counter->getInfo();
      counter = counter->getNext();
   }

   return myArray;
}

int LinkList::countBlocks() const
{
   int count = 0;
   LinkNode* counter = head;

   while(counter != NULL)
   {
      count++;
      counter = counter->getNext();
   }

   return count;
}

int LinkList::countAccesses() const
{
   int count = 0;
   LinkNode* counter = head;

   while(counter != NULL)
   {
      count += counter->numAccesses();
      counter = counter->getNext();
   }

   return count;
}

void LinkList::insert(const Type& e)
{
   LinkNode* counter = head;

   if(counter == NULL)
   {
      head = new LinkNode(e);
      mySize++;
      return;
   }

   if(e <= counter->getInfo())
   {
	 counter->setNext(new LinkNode(e, counter->getNext()));
	 mySize++;
	 return;
   }

   while(counter->hasNext())
   {
      if(e <= counter->getNext()->getInfo())
      {
	 counter->setNext(new LinkNode(e, counter->getNext()));
	 mySize++;
	 return;
      }
      else
      {
	 counter = counter->getNext();
      }
   }

   counter->setNext(new LinkNode(e));
   mySize++;
}

void LinkList::remove(const Type& e)
{
   LinkNode* counter = head;

   if(e < counter->getInfo())
   {
      return;
   }
   else if(e == counter->getInfo())
   {
      LinkNode* temp = counter;
      head = counter->getNext();
      counter = head;
      delete temp;
      mySize--;
      return;
   }

   while(counter->hasNext())
   {
      if(e < counter->getNext()->getInfo())
      {
	 return; 
      }
      else if(e == counter->getNext()->getInfo())
      {
	 LinkNode* temp = counter->getNext();
	 counter->setNext(counter->getNext()->getNext());
	 delete temp;
	 mySize--;
	 return;
      }
      else
      {
	 counter = counter->getNext();
      }
   }
}

void LinkList::clear()
{
   Type* myArray = array();
   int currentSize = mySize;
   
   for(int i = 0; i < currentSize; i++)
   {
      remove(myArray[i]);
   }
   mySize = 0;

   delete [] myArray;
}

LinkList& LinkList::operator=(const LinkList& lst)
{
   if(this != &lst)
   {
      Type* myArray = lst.array();
      this->clear();
      for(int i = 0; i < lst.size(); i++)
      {
	 this->insert(myArray[i]);
      }
      delete [] myArray;

   }

   mySize = lst.size();
   return *this;
}

bool LinkList::operator==(const LinkList& lst) const
{
   Type* myArray = this->array();
   Type* notMyArray = lst.array();

   if(this->size() == lst.size())
   {
      for(int i = 0; i < this->size(); i++)
      {
	 if(myArray[i] != notMyArray[i])
	 {
	   delete [] myArray;
	   delete [] notMyArray;
	   return false;
	 }
      }
      
      delete [] myArray;
      delete [] notMyArray;
      return true;
   }
   else
   {
      delete [] myArray;
      delete [] notMyArray;
      return false;
   }
}

ostream& operator<<(ostream& s, const LinkList& l)
{
   Type* myArray = l.array();

   for(int i = 0; i < l.size(); i++)
   {
      s<<myArray[i]<<" ";
   }

   delete [] myArray;

   return s;
}
