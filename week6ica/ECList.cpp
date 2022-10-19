#include "ECListNode.h"
#include "ECList.h"

// Linked list 
ECList :: ECList():pHead(NULL), numNodes(0) 
{
}
  
// insert node with value val after a node
// if node is NULL, insert to the front
void ECList :: Insert(int val, ECListNode *pPre){
	ECListNode *px = new ECListNode;
	px->SetValue(val);
	if( pPre == NULL ) {
		px->SetNext(pHead);
		pHead = px;
	} else {
		px->SetNext(pPre->GetNext());
		pPre->SetNext(px);
	}
	++numNodes;
}

// delete a node
void ECList :: Delete(ECListNode *pNode){
	ECListNode *pc = pHead;
	ECListNode *pPre = NULL;
	while( pc != NULL){
		if(pc == pNode){
			if(pPre == NULL){
				pHead = pHead->GetNext();
			} else {
				pPre->SetNext(pNode->GetNext());
			}
			--numNodes;
			return;
		}
		pPre = pc;
		pc = pc->GetNext();
	}
}

// get a node with value; if multiple nodes with the same value, return the first from head
ECListNode * ECList::GetNode(int val){
	ECListNode *pc = pHead;
	while(pc != NULL){
		if(pc->GetValue() == val){
			return pc;
		}
		pc = pc->GetNext();
	}
	return NULL;
}

// get the number of nodes in the list
int ECList:: GetSize() const{
	return numNodes;
}

