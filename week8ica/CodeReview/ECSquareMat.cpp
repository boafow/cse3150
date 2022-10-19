#include "ECSquareMat.h"

// square matrix

ECSquareMat :: ECSquareMat(int nDim)
{
    // nDim: dimension of matrix (number of rows or columns)
    listMatEntries.resize(nDim);
    for(int i=0; i<(int)listMatEntries.size(); ++i)
    {
        listMatEntries[i].resize(nDim);
    }
}

ECSquareMat :: ECSquareMat(const ECSquareMat &rhs) : listMatEntries(rhs.listMatEntries)
{
}

ECSquareMat :: ~ECSquareMat()
{
    listMatEntries.clear();
}

ECSquareMat & ECSquareMat :: operator=(const ECSquareMat &rhs)
{
    this->listMatEntries = rhs.listMatEntries;
    return *this;
}

int ECSquareMat :: GetDimension() const
{
    return listMatEntries.size();
}

void ECSquareMat :: SetValAt(int nRow, int nCol, int val)
{
    listMatEntries[nRow][nCol] = val;
}

int ECSquareMat :: GetValAt(int nRow, int nCol) const
{
    return listMatEntries[nRow][nCol];
}

ECSquareMat ECSquareMat :: operator+(const ECSquareMat &rhs)
{
    for(int i=0; i<GetDimension(); ++i)
    {
        for(int j=0; j<GetDimension(); ++j)
        {
            int val = GetValAt(i, j);
            val += rhs.GetValAt(i, j);
            SetValAt(i,j, val);
        }
    }
    return *this;
}

ECSquareMat ECSquareMat :: operator*(const ECSquareMat &rhs) 
{
    ECSquareMat res( GetDimension() );
    for(int i=0; i<GetDimension(); ++i)
    {
        for(int j=0; j<GetDimension(); ++j)
        {
            int val = 0;
            for(int k=0; k<GetDimension(); ++k)
            {
                val += GetValAt(i, k) * rhs.GetValAt(k, j);
            }
            res.SetValAt(i,j, val);
        }
    }
    return res;
}


