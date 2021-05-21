//METHOD 1 - correct but TLE
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void bin(int n)
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

int cntBitsPair(int A,int B)
{
    int count=0;
    int N = A^B;
    while(N)
    {
        N = N&(N-1);
        count++;
    }
    
    return count;
}

int cntBits(vector<int> &A) 
{
    long long sum = 0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            sum+=cntBitsPair(A[i],A[j]);
        }
    }
    
    sum = sum%1000000007;
    return 2*sum;
}

int main() 
{
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(5);
    
    cout <<"1 : 001"<<endl;
    cout <<"3 : 011"<<endl;
    cout <<"5 : 101"<<endl;
    int B = cntBits(A);
    cout << B;
    return 0;
}
