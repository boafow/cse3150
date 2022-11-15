#ifndef EC_TRANDING_NEWS_H
#define EC_TRANDING_NEWS_H

#include <vector>

class ECTrendingNews;

// Subscriber interface. DON'T CHANGE THIS
class ECSubscriber
{
public:
	virtual ~ECSubscriber() {}
    	virtual void Update() = 0;
    	virtual int ContractCost() const = 0;
};

// pay-per click subscriber
class ECPayPerClickSubscriber: public ECSubscriber 
{
	ECTrendingNews &tn;
public:
	ECPayPerClickSubscriber( ECTrendingNews &tn): tn(tn) {};
	virtual void Update();
        virtual int ContractCost() const { return 0; }


};

// Contract subscriber
class ECContractSubscriber : public ECSubscriber
{
	ECTrendingNews &tn;
public:
	ECContractSubscriber( ECTrendingNews &tn): tn(tn) {};
	virtual void Update() { /* read the news*/ } 
        virtual int ContractCost() const { return 100; }

};

// This is the subject
class ECTrendingNews
{
public:
	ECTrendingNews(): totalRevenue(0) { subscribers.clear(); }
	~ECTrendingNews();
	// add a subscriber
	void Subscribe(ECSubscriber *pSub);
	// remove a subscriber
	void UnSubscribe(ECSubscriber *pSub);
	// Notify news is available for view
	void Notify();
	// receive payment (assume in whole dollar)
	void ReceivePayment(int amount) { totalRevenue += amount; }
	// Get total revenue received
	int GetTotRevenue() const;
	
private:
	int totalRevenue;
	std::vector<ECSubscriber *> subscribers;
};


#endif
