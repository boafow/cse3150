#ifndef EC_TRIV_OBJ
#define EC_TRIV_OBJ

#include <vector>

// a trival object
class ECTrivObj
{
public:
	ECTrivObj(int idIn) : id(idIn) {}
	int GetId() const { return id; }
	
private:
	int id;
};

// manipulate a list of dynamic allocated trivial objects
class ECTrivObjList
{
public:
	ECTrivObjList();
	~ECTrivObjList();
	
	void AddTrivObj(int id);	// add a triv object with id
	void EraseTrivObj(int id);	// id: the id of the obj to remove
	int GetNumObjs() const;		// return the number of trival objs
	const ECTrivObj *GetObj(int pos) const;		// get the pos-th (0-based) object
	
private:
	std::vector<ECTrivObj *> vecTrivObjs;
};

#endif
