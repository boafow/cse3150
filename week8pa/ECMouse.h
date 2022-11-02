#ifndef ECMouse_h
#define ECMouse_h

#include <string>
#include "ECOrganism.h"

class ECMouse: virtual public ECMammals {
        ECOrganism* prey;
        int work1 = 20;
        int eatLimit = 10;
public:
        ECMouse(const std::string &name, ECOrganism* prey): ECMammals(name), prey(prey) {};
        void Work (double hour, int type);
        void hunt(ECOrganism* prey);
}



#endif /* ECMouse_h */
