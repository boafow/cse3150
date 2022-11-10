// Code for modeling a university's various units: department, office,
// college, etc
#include <vector>
// Generic interface. 
class ECUnit
{
public:
	virtual ~ECUnit(){};
	virtual int GetBudget() const = 0;

};

// Department
class ECDepartment : public ECUnit
{
public:
	ECDepartment(int b) : budget(b) {} 
	int GetBudget() const { return budget; }

private:
	int budget;
};

// Office
class ECOffice : public ECUnit
{
public:
  ECOffice(int b) : budget(b) {}
  int GetBudget() const { return budget; }

private:
  int budget;
};

// Composite
class ECCompositeUnit : public ECUnit
{
public:
  ECCompositeUnit()  {}
  ~ECCompositeUnit() {
	for( auto x : listUnits){
		delete x;
	}
  }
  
  int GetBudget() const {
	int total = 0;
	for(auto x : listUnits){
	       total += x->GetBudget();
	}
	return total;	
  }
  void AddChild(ECUnit *pUnit) {
	  listUnits.push_back(pUnit);
  }

private:
	std::vector<ECUnit *> listUnits;
};

