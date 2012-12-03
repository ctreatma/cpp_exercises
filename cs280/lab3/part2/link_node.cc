//link_node.cc

#include "link_node.h"

LinkNode::LinkNode(Type e)
{
   info = e;
   next = NULL;
   num_accesses = new int[1];
   *num_accesses = 0;
}

LinkNode::LinkNode(Type e, LinkNode* next)
{
   this->next = next;
   info = e;
   num_accesses = new int[1];
   *num_accesses = 0;
}

LinkNode::LinkNode(const LinkNode& n)
{
   info = n.getInfo();
   next = NULL;
   num_accesses = new int[1];
   *num_accesses = 0;
}

LinkNode::~LinkNode()
{
  delete num_accesses;
}

Type LinkNode::getInfo() const
{
   (*num_accesses)++;
   return info;
}

bool LinkNode::hasNext() const
{
   return next!=NULL;
}

LinkNode* LinkNode::getNext() const
{
   return next;
}

void LinkNode::setInfo(Type e)
{
   info = e;
}

void LinkNode::setNext(LinkNode* node)
{
   next = node;
}

int LinkNode::numAccesses() const
{
   return *num_accesses;
}

LinkNode& LinkNode::operator=(const LinkNode& n) {
  if (this != &n) {
    info = n.getInfo();
  }

  return *this;
}

bool LinkNode::operator==(const LinkNode& n) {
  return (getInfo() == n.getInfo());
}

ostream& operator<<(ostream& sout, LinkNode p) {
  sout << &p;

  return sout;
}

ostream& operator<<(ostream& sout, LinkNode* p) {
  sout << p->getInfo();

  return sout;
}
