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

 string intToRoman(int A) 
{

    // for thousands
    string m[] = {"", "M", "MM", "MMM"};
    
    // for hundreds
    string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    
    // for tens
    string x[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    
    // for ones
    string i[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    string thou = m[A/1000];
    string hund = c[(A%1000)/100];
    string tens = x[(A%100)/10];
    string ones = i[A%10];
    
    string iToR = thou + hund + tens + ones;
    
    return iToR;
}

int main()
{
    string str = "MMDLIX";
    cout <<"Roman is : "<< str << endl<<"Integer is : "<< romanToInt(str) <<endl<<endl;
    
    int N = 2559;
    cout <<"Integer is : "<< N << endl<<"Roman is : "<< intToRoman(N) <<endl<<endl;
    
}
