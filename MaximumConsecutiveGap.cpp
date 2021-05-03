#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int Solution::maximumGap(const vector<int> &A)
{
    vector<int> vec;
    vec = A;
    sort(vec.begin(),vec.end());
    if(A.size()<2)
        return 0;
        
    vector<unsigned int> v;
    for(int i=0;i<A.size()-1;i++)
    {
        v.push_back(vec[i+1] - vec[i]); 
    }
    unsigned int max = *max_element(v.begin(), v.end());;
    return max;
}
