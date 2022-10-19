#include <iostream>
#include "ECListNode.h"
using namespace std;

ECListNode* MergeTwoLists(ECListNode* l1, ECListNode* l2);

int main()
{
  ECListNode v1(1), v2(2), v3(4), v4(1), v5(3), v6(4);
  v1.SetNext(&v2);
  v2.SetNext(&v3);
  v4.SetNext(&v5);
  v5.SetNext(&v6);

  ECListNode *pn = MergeTwoLists(&v1, &v4);
  cout << "Merged list: ";
  ECListNode *pncurr = pn;
  while(pncurr != NULL)
  {
    cout << pncurr->GetValue() << "  ";
    pncurr = pncurr->GetNext();
  }  
  cout << endl;

}

