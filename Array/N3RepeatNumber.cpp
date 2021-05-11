#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int MVA2(const vector<int> &A)
{
    //Moore Voting Algorithm for N/2
    int ME=A[0],count1=1,i=1;
    while(i<A.size())
    {
        if(A[i] == A[i-1])
            count1++;
        else if(A[i]!=A[i-1])
            count1--;
        i++;
        if(count1 == 0)
        {
            ME = A[i];
            if(i>=A.size())
              ME = A[i-1];
            count1 = 1;
        } 
            
    }
    return ME;
}

int MVA3(const vector<int> &A)
{
    //Moore Voting Algorithm for N/2
    int x=-1,y=-1,countx=0,county=0;
    for(int i=0;i<A.size();i++)
    {
        if(x==A[i])
            countx++;
        else if(y==A[i])
            county++;
        else if(countx==0)
        {
            x = A[i];
            countx=1;
        }
        else if(county==0)
        {
            y=A[i];
            county=1;
        }
        else
        {
            county--;
            countx--;
        }
    }
    int nx = count(A.begin(), A.end(), x);
    int ny = count(A.begin(), A.end(), y);
    
    if(nx>=ny)
        return x;
    else
        return y;    
}

int Solution::repeatedNumber(const vector<int> &A) 
{
    int ME = MVA3(A);
    
    int n = count(A.begin(), A.end(), ME);
    //int nE = count(A.begin(), A.end(), A[A.size()-1]);
    if(n > A.size()/3)
        return ME;
    else
        return -1;
    
}
