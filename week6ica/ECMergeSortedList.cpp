#include "ECList.h"
#include <cstddef>

// Merge two sorted lists, with starting nodes l1 and l2 respectively
ECListNode* MergeTwoLists(ECListNode* l1, ECListNode* l2){
	ECListNode *head;
	ECList ll;
	if(l1->GetValue() <= l2->GetValue()){
		head = l1;
		ll.Insert(l1->GetValue(), NULL);
		ll.Insert(l2->GetValue(), NULL);
	} else {
		head = l2;
		ll.Insert(l2->GetValue(), NULL);
		ll.Insert(l1->GetValue(), NULL);
	}
	
	ECListNode* currentl1 = l1->GetNext();
	ECListNode* currentl2 = l2->GetNext();

	while(currentl1 != NULL || currentl2 != NULL){
		if(currentl1 == NULL && currentl2 == NULL) return head;
		if(currentl1 != NULL && currentl2 == NULL) {
			ll.Insert(currentl1->GetValue(), NULL);
			return head;
		} else if (currentl1 == NULL && currentl2 != NULL){
			ll.Insert(currentl2->GetValue(), NULL);
			return head;
		} else {
			if(currentl1->GetValue() <= currentl2->GetValue()){
				ll.Insert(currentl1->GetValue(), NULL);
				ll.Insert(currentl2->GetValue(), NULL);
			} else {
				ll.Insert(currentl2->GetValue(), NULL);
				ll.Insert(currentl1->GetValue(), NULL);
			}
		}
		currentl1 = currentl1->GetNext();
		currentl2 = currentl2->GetNext();
	}
	return head;
}


