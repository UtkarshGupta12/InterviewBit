#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void bin(unsigned int n)
{
    long i;
    cout << "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        cout << "1";
      }
      else
      {
        cout << "0";
      }
    }
    cout << endl;
}

int findMinXor(vector<int> &A)
{
    sort(A.begin(),A.end());
    int ans=INT_MAX;
    
    for(int i=0;i<A.size();i++)
        ans = min(ans,A[i]^A[i+1]);
    
    return ans;
}

int main() 
{
    vector<int> A;
    A.push_back(0);
    A.push_back(4);
    A.push_back(7);
    A.push_back(9);
    
    int B = findMinXor(A);
    cout << B;
    return 0;
}
