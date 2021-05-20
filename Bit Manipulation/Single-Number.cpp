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

int singleNumber(const vector<int> &A) 
{
    int ans = 0;
    for(int i=0;i<A.size();i++)
        ans = A[i]^ans;
    
    return ans;
}

int main() 
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(2);
    A.push_back(3);
    A.push_back(1);
    
    int B = singleNumber(A);
    
    return 0;
}
