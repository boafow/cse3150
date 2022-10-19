#include "ECSquareMat.h"
using namespace std;

ECSquareMat::ECSquareMat(int nDim) {
	listMatEntries.resize(nDim);        //number rows resize
        for(int r = 0; r < nDim; ++r){
                listMatEntries[r].resize(nDim);
                for(int c = 0; c < nDim; ++c){ 
                        listMatEntries[r][c] = 0;
                }
        }

}

ECSquareMat::~ECSquareMat(){
	listMatEntries.clear();
}

ECSquareMat& ECSquareMat :: operator=(const ECSquareMat &rhs){
	listMatEntries = rhs.listMatEntries;
	return *this;
}

int ECSquareMat::GetDimension() const{
	return listMatEntries.size();
}

void ECSquareMat::SetValAt(int nRow, int nCol, int val){
	for(int i = 0; i < GetDimension(); ++i){
		for(int j = 0; j < GetDimension(); ++j){
			if(i == nRow && j == nCol) listMatEntries[i][j] = val;
		}
	}
}

int ECSquareMat::GetValAt(int nRow, int nCol)const {
	for(int i = 0; i < GetDimension(); ++i){
                for(int j = 0; j < GetDimension(); ++j){
                        if(i == nRow && j == nCol) return listMatEntries[i][j];
                }
        }
	return false;
}

ECSquareMat ECSquareMat :: operator+(const ECSquareMat &rhs){
	ECSquareMat result(GetDimension());
	for(int i = 0; i < GetDimension(); ++i){
		for(int j = 0; j < GetDimension(); ++j){
			result.SetValAt(i,j,(listMatEntries[i][j] + rhs.GetValAt(i,j)));
		}
	}
	return result;
}

ECSquareMat ECSquareMat :: operator*(const ECSquareMat &rhs){
	ECSquareMat result(GetDimension());
	for(int i = 0; i < GetDimension(); ++i){
		for(int j = 0; j < GetDimension(); ++j){
			int sum = 0;
			for(int k = 0; k < GetDimension(); ++k){
				sum += listMatEntries[i][k] * rhs.GetValAt(k,j);
			}
			result.SetValAt(i,j,sum);
		}
	}
	return result;
}


