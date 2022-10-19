#include "ECListNode.h"

// Merge two sorted lists, with starting nodes l1 and l2 respectively
ECListNode* MergeTwoLists(ECListNode* l1, ECListNode* l2)
{
    ECListNode* start = NULL;
    ECListNode* cur;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->GetValue() < l2->GetValue())
        {
            if (start == NULL)
            {
                start = l1;
                cur = start;
            }
            else
            {
                cur->SetNext(l1);
                cur = cur->GetNext();
            }
            l1 = l1->GetNext();
        }
        else
        {
            if (start == NULL)
            {
                start = l2;
                cur = start;
            }
            else
            {
                cur->SetNext(l2);
                cur = cur->GetNext();
            }
            l2 = l2->GetNext();
        }
    }

    while (l1 != NULL)
    {
        cur->SetNext(l1);
        l1 = l1->GetNext();
    }
    while (l2 != NULL)
    {
        cur->SetNext(l2);
        l2 = l2->GetNext();
    }
    return start;
}

