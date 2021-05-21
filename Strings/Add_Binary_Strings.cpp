// Not a possible solution because numbercan be more than 2^64 so out of long long range  
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string int2binary(long long unsigned A)
{
    string bin="";
    while(A)
    {
        if(A&1==1)
            bin+='1';
        else
            bin+='0';
        A>>=1;    
    }
    reverse(bin.begin(),bin.end());
    cout << bin << endl;
    return bin;
}

string addBinary(string A, string B) 
{
    int size_A = A.size();
    int size_B = B.size();
    string ans = "";
    long long unsigned a=0,b=0;
    
    for(int i=0;i<size_A;i++)
        if(A[i]=='1')
            a+=pow(2,size_A-i-1);
    
    for(int i=0;i<size_B;i++)
        if(B[i]=='1')
            b+=pow(2,size_B-i-1);
    
    cout <<"a : "<<a<<endl<<"b : "<<b<<endl;
    cout <<"a+b : "<<a+b<<endl;
    
    ans = int2binary(a+b);
    
    return ans;
}

int main()
{
        //101111000100100111001010101001110100001100001010110011100100011010100000
    //100100111001010101001110100001100001010110011100100100010011000
    string A = "10001100010111000101100010100110001001101010000010011010";
    string B = "101111000100100100111110010010101110101001100100101001111010011000000110";
    cout << addBinary(A,B) << endl;
    
}
