// NOT COMPLETED YET
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

int divide(int a, int b)
{
    int numbits_num = 0;
    int numbits_den = 0;
    int A = a, B = b;
    while(A)
    {
        A>>=1;
        numbits_num++;
    }
    while(B)
    {
        B>>=1;
        numbits_den++;
    }
    
    
    cout <<"Numbits_Numerator : "<<numbits_num<<endl<<"Numbits_Denominator : "<<numbits_den<<endl;
    
    if(numbits_den>numbits_num)
        return 0;
    
    return numbits_num-numbits_den;
}

int main() 
{
    int A = divide(56,55);
    cout << A << endl;
}
