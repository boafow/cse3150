#include "ECPolynomial.h"
#include <iostream>
using namespace std;

ECPolynomial::ECPolynomial(const std::vector<double> &listCoeffsIn){
	coeffs = listCoeffsIn;
}

ECPolynomial::ECPolynomial(const ECPolynomial &rhs){
	coeffs = rhs.coeffs;
}

int ECPolynomial::GetDegree() const{
	int n = coeffs.size();
	if(coeffs.empty()) return 0;
	for(int i = n; i > 0; --i){
		if(coeffs[n] <= 0.00000000001){
			n-=1;
		} else {
			return n;
		}
	}
	return n-1;
}

double ECPolynomial::GetCoeff(int d) const {
	if(coeffs.empty()) return 0.0;
	return coeffs[d];
}

ECPolynomial ECPolynomial::Scale(double factor){
	std::vector<double> res(coeffs.size(), 0.0);
        for(int i = 0; i < coeffs.size(); ++i){
		res[i] += coeffs[i] * factor;
        }
	for(int i = res.size()-1; i > 0; --i){
		if (res[i] <= 0.00000000001)
			res.erase(res.begin() + i);
	}
        ECPolynomial result(res);
        return result;
}

ECPolynomial ECPolynomial::operator+(const ECPolynomial &rhs) const{
	int size = max(rhs.coeffs.size(), coeffs.size());
	vector<double> res(size);

	for(int i = 0; i < coeffs.size(); ++i){
		res[i] = coeffs[i];
	}

	for(int i = 0; i < rhs.coeffs.size(); ++i){
		res[i] += rhs.coeffs[i];
	}
	for(int i = res.size()-1; i > 0; --i){
                if (res[i] <= 0.00000000001)
                        res.erase(res.begin() + i);
        }

	ECPolynomial result(res);
	return result;
}

ECPolynomial ECPolynomial::operator*(const ECPolynomial &rhs) const{
	std::vector<double> vecIn(coeffs.size()*rhs.coeffs.size(), 0.0);
	for(int i = 0; i < coeffs.size(); ++i){
		for(int j = 0; j < rhs.coeffs.size(); ++j){
			vecIn[i+j]+= coeffs[i] * rhs.coeffs[j];
		}
	}
	for(int i = vecIn.size()-1; i > 0; --i){
                if (vecIn[i] <= 0.00000000001)
                        vecIn.erase(vecIn.begin() + i);
        }

	ECPolynomial res(vecIn);
	return res;
}
ECPolynomial ECPolynomial::DivideBy(const ECPolynomial &rhs, ECPolynomial &remainder) const {
	ECPolynomial res(coeffs);
	return res;
}

void ECPolynomial::Dump() const {
	for(auto coeff : coeffs){
		cout << coeff << endl;
	}
}
