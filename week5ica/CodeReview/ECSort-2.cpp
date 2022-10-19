#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void Merge(int l1[], int l1size, int l2[], int l2size, int l[]) {
    int i = 0;
    int j = 0;
    while (i < l1size || j < l2size) {
        if (j == l2size || (i < l1size && l1[i] <= l2[j])) {
            l[i+j] = l1[i];
            i++;
        } else {
            l[i+j] = l2[j];
            j++;
        }
    }
}

void MergeSort(int listInts[], int size) {
    if (size == 1 || size == 0)
        return;
    else {
        int mid = size / 2;
        int j = 0;
        int l1[mid];
        for (int i=0; i<mid; i++) {
            l1[i] = listInts[j++];
        }
        int l2[size-mid];
        for (int i=0; i<size-mid; i++) {
            l2[i] = listInts[j++];
        }
        MergeSort(l1, mid);
        MergeSort(l2, size-mid);
        Merge(l1, mid, l2, size-mid, listInts);
    }
}
void ECSort(int listInts[], int size)
{
  // Sort the numbers in the list
    if (size == 1 || size == 0) {
       return;
    } else {
        MergeSort(listInts, size);
    }
}
