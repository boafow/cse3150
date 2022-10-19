#ifndef EC2SUM_H
#define EC2SUM_H

// EC2SUM: decide whether each number in listTargets is a sum of two numbers (duplicates allowed) in
// listNumbers. Store True/False in list2SUMRes for each target number (note: list2SumRes has been allocated
// memory by the caller) 
void EC2SUM( const int listNumbers[], int sizeNumbers, const int listTargets[], int szTargets, bool list2SUMRes[] );

#endif  // EC2SUM_H
