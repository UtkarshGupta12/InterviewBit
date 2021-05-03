#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::repeatedNumber(const vector<int> &A)
{   
    vector<int> v,ans;
    v=A;
    sort(v.begin(),v.end());
    long long n = v[v.size()-1];
    long long sum = accumulate(v.begin(),v.end(), 0);
    
    
    for(int i = 0;i<v.size();i++)
    {
        if((v[i] == i) || (v[i] - 2 == i))
            { 
            if((v[i] == v[i+1])||(v[i] == v[i-1]))
              {
              ans.push_back(v[i]);
              break;
              }
            }  
    }
    
    long long B = ans[0] - sum + n*(n+1)/2;
    ans.push_back(B);
    return ans;
}
