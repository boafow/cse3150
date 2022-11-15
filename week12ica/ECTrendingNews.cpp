#include "ECTrendingNews.h"

// Your code goes here
// pay-per click subscriber
ECPayPerClickSubscriber 

// Contract subscriber
ECContractSubscriber 

// This is the subject
ECTrendingNews :: ECTrendingNews()
{
}
ECTrendingNews :: ~ECTrendingNews()
{
}

// add a subscriber
void ECTrendingNews :: Subscribe(ECSubscriber *pSub)
{
	subscribers.push_back(pSub);
}
// remove a subscriber
void ECTrendingNews :: UnSubscribe(ECSubscriber *pSub)
{
	for(int i = 0; i < subscribers.size(); ++i){
		if(pSub == subscribers[i]){
			subscribers.erase(subscribers.begin()+i);
		}
	}
}
// Notify news is available for view
void ECTrendingNews :: Notify()
{
}
// receive payment (assume in whole dollar)
void ECTrendingNews :: ReceivePayment(int amount)
{
}
// Get total revenue received
int ECTrendingNews :: GetTotRevenue() const 
{
}
        
