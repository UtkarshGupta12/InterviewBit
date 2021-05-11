#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    vector<int> A;
    vector<int> D;
    A = arrive;
    D = depart;
    
    sort(A.begin(),A.end());
    sort(D.begin(),D.end());
    
    int conflict=0, j=0, i=0;
    
    while(i<A.size() && j<D.size())
    {
        if(A[i]<D[j])
        {
            conflict++;
            i++;
        }
        else
        {
            conflict--;
            j++;
        }
        if(conflict > K)
        return false;
    }

       return true;
}
    
