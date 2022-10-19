#include "ECListNode.h"

// Merge two sorted lists, with starting nodes l1 and l2 respectively
ECListNode* MergeTwoLists(ECListNode* l1, ECListNode* l2)
{
  ECListNode* p1 = l1;
  ECListNode* p2 = l2;
  ECListNode* res = NULL;
  if(p1->GetValue() < p2->GetValue()){
    res = p1;
    p1 = p1->GetNext();
  }
  else{
    res = p2;
    p2 = p2->GetNext();
  }
  ECListNode* p3 = res;
  while(p1 != NULL && p2 != NULL){
    if(p1->GetValue() < p2->GetValue()){
      p3->SetNext(p1);
      p1 = p1->GetNext();
    }
    else{
      p3->SetNext(p2);
      p2 = p2->GetNext();
    }
    p3 = p3->GetNext();
  }
  while(p1 != NULL){
    p3->SetNext(p1);
    p1 = p1->GetNext();
    p3 = p3->GetNext();
  }
  while(p2 != NULL){
    p3->SetNext(p2);
    p2 = p2->GetNext();
    p3 = p3->GetNext();
  }
  return res;
}

