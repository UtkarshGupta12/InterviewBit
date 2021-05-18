#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int val(char c)
{
    if(c == 'I') return 1;
    if(c == 'V') return 5;
    if(c == 'X') return 10;
    if(c == 'L') return 50;
    if(c == 'C') return 100;
    if(c == 'D') return 500;
    if(c == 'M') return 1000;
    
    return -1;
}

int romanToInt(string A)
{
    int sum = 0;
    for(int i=0;i<A.size();i++)
    {
        if(val(A[i+1])>val(A[i]))
            sum -=val(A[i]);
        else
            sum +=val(A[i]);
    }
    
    
    return sum;
}

int main()
{
    string str = "MMCCCXLIV";
    cout << str << endl;
    cout << romanToInt(str) <<endl;
    
}
