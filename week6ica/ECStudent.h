#ifndef _EC_STUDENT_H
#define _EC_STUDENT_H

#include <string>

// Student class
class ECStudent
{
public:
  ECStudent(const std::string &nameIn) : name(nameIn), _mt(0), _final(0), _hw(0) {} 
  double GetMT() const { return _mt; }
  void SetMT(double s) { _mt = s; }
  double GetFinal() const { return _final; }
  void SetFinal(double s) { _final = s; }
  double GetHW() const { return _hw; }
  void SetHW(double s) { _hw = s; }
  std::string GetName() const { return name; }
  // ave score: 20% HW, 30% Midterm, 50% Final
  double GetAve() const { return (0.2 * GetHW()) + (0.3 * GetMT()) + (0.5 * GetFinal()); }

private:
	std::string name;
    	double _mt;
	double _final;
	double _hw;

};


#endif
