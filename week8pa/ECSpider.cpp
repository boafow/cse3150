#include "ECSpider.h"


void ECSpider::DoSomething(const ECOrganism &rhs){
	if(rhs == NULL) return;
	ECArthopods * arth = dynamic_cast<ECArthopods *>(rhs);
	if(arth != NULL){ rhs.vitality == 0; }
}
