#include "ECPointerString.h"
using namespace std;

ECStringPtr::ECStringPtr():ptr(NULL){}	//default
ECStringPtr::ECStringPtr(const std::string &strInit){
	ptr = new string(strInit);	//custom
}

ECStringPtr::ECStringPtr(const ECStringPtr &rhs) {
	if(rhs.GetPtr() != NULL){
		ptr = new string(*rhs.GetPtr());
	} else {
		ptr = NULL;
	}
}

ECStringPtr::ECStringPtr(ECStringPtr &&rhs) { 
	ptr = std::move(rhs.ptr);
	
}

ECStringPtr::~ECStringPtr(){
 	delete ptr;
}

ECStringPtr & ECStringPtr::operator=(const ECStringPtr &rhs){
       	if(rhs.GetPtr() != NULL){
		ptr  = new string(*rhs.GetPtr()); //assignment operator
	} else {
		delete ptr;
		ptr = NULL;
	}
	return *this;
}

void ECStringPtr::SetString(const std::string &strToSet){
	delete ptr;
	ptr = new string(strToSet);
}

const std::string * ECStringPtr::GetPtr() const {
	return ptr;
}

ECStringPtr ECStringPtr:: Duplicate() const {
	ECStringPtr res(*this);
	if(GetPtr() != NULL){
		res.SetString(*ptr + *ptr);
	} 
	return res;
}

