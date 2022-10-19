#ifndef _EC_LIST_NODE_H
#define _EC_LIST_NODE_H

#include <iostream>

// Class for linked list node
class ECListNode
{
public:
  ECListNode() : pNext(NULL), value(0) {}
  ECListNode(int v) : pNext(NULL), value(v) {}
  ECListNode *GetNext() const { return pNext; }
  void SetNext(ECListNode *pn) { pNext = pn; }
  int GetValue() const { return value; }
  void SetValue(int v) { value = v; }

private:
  ECListNode *pNext;
  int value;
};

#endif
