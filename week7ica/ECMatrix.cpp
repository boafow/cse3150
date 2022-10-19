#include "ECMatrix.h" 
#include <iostream>

ECMatrix :: ECMatrix(){}

ECMatrix::ECMatrix(int nr, int nc){
   	listElements.resize(nr);	//number rows resize
	for(int r = 0; r < nr; ++ r){
		listElements[r].resize(nc);
		for(int c = 0; c < nc; ++c){
			listElements[r][c] = 0.0;
		}
	}
}

ECMatrix::ECMatrix(const ECMatrix &rhs){
	listElements = rhs.listElements;
}

ECMatrix &ECMatrix::operator=(const ECMatrix &rhs){
	listElements = rhs.listElements;
	return *this;
}

ECMatrix::ECMatrix(ECMatrix &&rhs){
	listElements = std::move(rhs.listElements);	
}

// Get num of rows/columns
int ECMatrix:: GetNumRows() const {
  return listElements.size();
}

int ECMatrix :: GetNumCols() const{
	if(GetNumRows() == 0) return 0;
	return listElements[0].size();
}

// Get/set an element in the matrix
double ECMatrix::GetVal(int r, int c) const
{
  return listElements[r][c];
}
void ECMatrix::SetVal(int r, int c, double val)
{
  listElements[r][c] = val;
}

// Scale by a factor
ECMatrix ECMatrix:: Scale(double factor) const {
	ECMatrix result(*this);
	for(int r = 0; r < GetNumRows(); ++r){
		for(int c = 0; c < GetNumCols(); ++c){
			result.listElements[r][c] *= factor;
		}
	}
	return result;
}

