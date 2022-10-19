// This code seg-faults in Gradescope. What is the problem?
#include "ECPolynomial.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// Construct a polynomial with coefficients
// first position is the constant term and [i] is the coefficient of x^i
// Example: given [1, 3, 0, 2], polynomial = 1 + 3x + 2x^3
// We assume listCoeffsIn is not empty
// Note: the last term in listCoeffsIn should not be zero (unless its length is 1). 
// For example, if given [1, 3, 0], we should simply it to [1,3]. 
// Since coefficient is a double, we consider a value is practically zero if its absolute value is sufficiently small (say less than 1e^(-10))
ECPolynomial :: ECPolynomial(const std::vector<double> &listCoeffsIn) {
    if (listCoeffsIn.size() == 0) {
        degree = 0;
        return;
    }

    if (listCoeffsIn.size() == 1) {
        coefficient.push_back(listCoeffsIn[1]);
        degree = 0;
        return;
    }

    // for each coefficient, add it to the vector of coefficients
    for (double coeff : listCoeffsIn) {
        coefficient.push_back(coeff);
    }

    // then, pop off the last monomials at the end of the vector if they're equal to 0
    int end = coefficient.size() - 1;

    while (coefficient[end] == 0 || fabs(coefficient[end]) < 0.0000000001) {
        coefficient[end] = 0;
        end--;
        coefficient.pop_back();
    }

    degree = coefficient.size() - 1;
}

// Copy constructor
ECPolynomial :: ECPolynomial(const ECPolynomial &rhs) {
    if (rhs.coefficient.empty() || rhs.degree == 0) {
        degree = 0;
        coefficient.push_back(0);
    }

    else {
        degree = rhs.degree;
        coefficient = rhs.coefficient;
    }
}

// Custom constructor that initializes to be x^deg, i.e. a single term with certain degree
ECPolynomial :: ECPolynomial(int d) {
    degree = d;

    for (int i = 0; i < degree; i++) {
        coefficient.push_back(0);
    }

    if (degree == 0) {
        coefficient[degree] == 0;
    }

    else {
        coefficient[degree] = 1;
    }
}

// Get the degree. Example: if polynomial=1+x+3x^3, degree=3
int ECPolynomial :: GetDegree() const {
    return degree;
}

// Get the coefficients. Example: if polynomial=1+x+3x^3, coefficients(0)=1, coefficients(1)=1, coefficients(2)=0, coefficients(3)=2
double ECPolynomial :: GetCoeff(int d) const {
    // if the polynomial is empty, return 0
    if (coefficient.size() == 0 || d > degree) {
        return 0;
    }

    return coefficient[d];
}   

// Divide a polynomial by another, and return the quotient (and save the remainder to the passed in parameter called remainder)
// Example: if we divide x^3-2x^2-4 by x-3, then quotient = x^2+x+3 and remainder is 5
// For now, assume rhs (denominator) is zero
ECPolynomial ECPolynomial :: DivideBy(const ECPolynomial &rhs, ECPolynomial &remainder) const {
    Dump();
    rhs.Dump();
    
    if (rhs.degree == 0) {
        ECPolynomial res(0);
        res.coefficient[0] == 0;
        remainder.coefficient[0] = 0;

        return res;
    }

	std::vector<double> quotient, divisor;

    for (auto it = coefficient.rbegin(); it != coefficient.rend(); it++) {
        quotient.push_back(*it);
    }

    for (auto it = rhs.coefficient.rbegin(); it != rhs.coefficient.rend(); it++) {
        divisor.push_back(*it);
    }

	int n = divisor[0];
	for (int i = 0; i < coefficient.size() - (divisor.size() - 1); i++) {
		quotient[i] /= n;
		int c = quotient[i];

		if (c != 0) {
			for (int j = 1; j < divisor.size(); j++) {
				quotient[i + j] += -1 * (divisor[j]) * c;
			}
        }

	}

    //remainder.Dump();

    remainder.coefficient[0] = quotient[quotient.size() - 1];
    //cout <<  remainder.coefficient[0] << endl;

    ECPolynomial result(0);
    result.coefficient[0] == 0;

    for (auto it = quotient.rbegin() + 1; it != quotient.rend(); it++) {
        result.coefficient.push_back(*it);
    }

    result.degree = degree - rhs.degree;

	return result;
}

// This is for testing only. It can be useful to dump out the polynomial (in some format) to the terminal for debugging
void ECPolynomial :: Dump() const {
    for (double i : coefficient) {
        cout << i << " ";
    }

    cout << endl;

    cout << "degree: " << degree << endl;
}

// *************************
// Test code

int main()
{
  // Test case 13
    vector<double> vec1;
    vec1.push_back(-17);
    vec1.push_back(38);
    vec1.push_back(-12);
    vec1.push_back(1);
    ECPolynomial poly1(vec1);
    vector<double> vec2 ;
    vec2.push_back(-7);
    vec2.push_back(1);
    ECPolynomial poly2(vec2);

    vector<double> list;
    list.push_back(1.0);
    ECPolynomial poly4(list);
    ECPolynomial poly3 = poly1.DivideBy(poly2, poly4);
    //REQUIRE(poly4.GetDegree() == 0);
    //REQUIRE(poly4.GetCoeff(0) == 4);
    //REQUIRE(poly3.GetDegree() == 2);
    //REQUIRE(poly3.GetCoeff(0) == 3);    
    //REQUIRE(poly3.GetCoeff(1) == -5);
    //REQUIRE(poly3.GetCoeff(2) == 1);
    cout << "Quotient: ";
    poly3.Dump();
    cout << "Remainder: ";
    poly4.Dump();
}

