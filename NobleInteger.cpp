#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A)
{
    vector<int> B;
    B = A;
    sort(B.begin(),B.end());
    int count=0;
    for(int i=0;i < B.size()-1;i++)
    {
        if(B[i] == B[i+1]) 
            continue;
        if((B[i] == B.size() - i -1) && (B[i] >= 0 ))
            count++;
    }
    if(count>=1)
        return 1;
    
    
    else if(B[B.size()-1] == 0)
        return 1;
    else
        return -1;
    
}
