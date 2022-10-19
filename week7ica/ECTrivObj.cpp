#include "ECTrivObj.h"

using namespace std;

// manipulate a list of dynamic allocated trivial objects

ECTrivObjList :: ECTrivObjList()
{
}
ECTrivObjList :: ~ECTrivObjList()
{
  // your code
}
	
void ECTrivObjList :: AddTrivObj(int id)
{
  // add a triv object with id
  // your code
}
void ECTrivObjList :: EraseTrivObj(int id)
{
  // id: the id of the obj to remove
  // search and remove; 
  // your code
}
int ECTrivObjList :: GetNumObjs() const 
{
  // return the number of trival objs
  // your code 
  return vecTrivObjs.size(); 
}	
const ECTrivObj * ECTrivObjList :: GetObj(int pos) const 
{ 
  // get the pos-th (0-based) object
  // your code
}

