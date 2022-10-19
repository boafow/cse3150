// Part of merge sort code, submitted by a student
void merge(int *arr, int low, int high, int mid)
{
  int res[1000]; // initialize res array
  int lP = low;
  int cP = low;     // left and copy pointer set to low index
  int rP = mid + 1; // right pointer set to first element after mid
  while (lP <= mid && rP <= high)
  {
    if (rP == 1000 || lP == 1000 || cP == 1000)
    {
      // cout << cP << "/" << lP << "/" << rP << '\t' << low << "/" << mid << "/" << high << endl;
      break;
    }
    if (arr[lP] <= arr[rP])
    {
      res[cP] = arr[lP]; // add lower value to res
      cP++;              // iterate pointers used
      lP++;
    }
    else
    { // do opposite
      res[cP] = arr[rP];
      cP++; // iterate pointers used
      rP++;
    }
  }
  // add remaining values if missed
  while (lP <= mid)
  {
    res[cP] = arr[lP];
    cP++;
    lP++;
  }
  while (rP <= high)
  {
    res[cP] = arr[rP];
    cP++;
    rP++;
  }
  // change values of arr to sorted values from res
  for (int i = low; i <= high; ++i)
  {
    arr[i] = res[i];
  }
}

