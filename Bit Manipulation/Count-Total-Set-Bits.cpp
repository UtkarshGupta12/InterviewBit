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

int solve2(int A)
{
    int N = A;
    int numbits=0;
    while(A)
    {
        A>>=1;
        numbits++;
    }
    
    cout <<"Numbits : "<< numbits << endl;
    long long numones = 0;
    numones += (numbits-1)*((int)pow(2,numbits-2));
    cout<<"Numones : "<<numones<<endl;
    
    A = N;
    int n = A-pow(2,numbits-1)+1;
    
    numones +=n;
    cout<<"Numones : "<<numones<<endl;
    
    for(int i=1;i<numbits;i++)
    {
        int denominator = pow(2,i);
        int numerator = pow(2,i-1);
        numones += (n/denominator)*numerator;
        if(n%denominator - numerator > 0)
            numones += n%denominator - numerator;
        
        cout<<"Numones : "<<numones<<endl;
    }
    
    return numones%1000000007;
}

int main() 
{
    //int B = solve1(13);
    int C = solve2(9);
    //cout << B << endl<<endl<<endl;
    cout << C << endl;
    return 0;
}
