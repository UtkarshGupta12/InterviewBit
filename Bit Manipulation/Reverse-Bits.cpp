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

unsigned int reverse(unsigned int A)
{
    unsigned int B=0;
    for(int i=0;i<32;i++)
    {
        B = B << 1;
        B = B|A&1;
        //cout << "A : ";
        //bin(A);
        cout << "B : ";
        bin(B);
        A = A >> 1;
    }

    return B;   
}

int main() 
{
    unsigned int B,A = 15;
    
    bin(A);
    B = reverse(A);
    bin(B);
    return 0;
}
