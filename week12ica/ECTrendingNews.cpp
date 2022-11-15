#include "ECTrendingNews.h"

// Your code goes here
// pay-per click subscriber
void ECPayPerClickSubscriber::Update(){
       tn.ReceivePayment(1);
}       

// This is the subject
ECTrendingNews :: ~ECTrendingNews()
{
}

// add a subscriber
void ECTrendingNews :: Subscribe(ECSubscriber *pSub)
{
	subscribers.push_back(pSub);
	ReceivePayment(pSub->ContractCost());
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
	for(auto pSub : subscribers){
		pSub->Update();
	}
}

// Get total revenue received
int ECTrendingNews :: GetTotRevenue() const 
{
}
        
