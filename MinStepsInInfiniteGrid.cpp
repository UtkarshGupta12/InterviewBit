#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int Solution::coverPoints(vector<int> &A,vector<int> &B)
{
    int steps = 0;
    
    for(int i=0;i<A.size()-1;i++)
    {
        int x = abs(A[i] - A[i+1]);
        int y = abs(B[i] - B[i+1]);
        
        steps += max(x,y);
    }
    return steps;
}
