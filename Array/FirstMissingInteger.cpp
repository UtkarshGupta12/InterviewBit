#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool areSame(vector<int> &arr)
{
  int first = arr[0];
  int n = arr.size();
  for (int k = 1; k < n; k++)
    if (arr[k] != first)
      return 0;
  return 1;
}

int Solution::firstMissingPositive(vector<int> &A)
{
    // Removing all negative elements from the ctor A
    auto it = remove_if(A.begin(), A.end(),  [](const int i) {return i <= 0; });
    A.erase(it, A.end());
    int max = *max_element(A.begin(), A.end());
    
    sort(A.begin(),A.end());
    int c;
    if(A[0] >=2  || A.size() == 0)
        return 1;
    else if(A[0] == 1 && areSame(A))
        return 2;
    else if(accumulate(A.begin(), A.end(), 0) == (max*(max+1))/2 && A[0] == 1)    
        return max+1;
    else    
    {
        int j=0;
        
        while(A[j] == j+1)
            {
                c = A[j]+1;
                j++;
            }
        
        return c;
        
    }
}
