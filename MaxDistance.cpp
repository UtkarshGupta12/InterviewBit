//Showing some error

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> sortUsingSecondArr(vector<int> &A)
{
    vector<int> A1;
    int n = A.size();
    
    for(int i=0;i<n;i++)
    {
        A1.push_back(i);
    }

    pair<int, int> pair_arr[n];
    for (int i = 0; i < n; i++) 
    {
        pair_arr[i].first = A[i];
        pair_arr[i].second = A1[i];
    }
    sort(pair_arr, pair_arr + n);
    for (int i = 0; i < n; i++) 
    {
      A[i] = pair_arr[i].first;
      A1[i] = pair_arr[i].second;
    }
    
    return A1;
}

int max_difference(vector<int> &A)
{
    int i=0,j=1,temp=0,c=0;
    while(i<A.size() && j<A.size())
    {
        if(A[j]>A[i] && j>i)
        {
            c = A[j]-A[i];
            j++;
            temp=max(c,temp);
        }
        else if(A[j] == A[i] && j>i)
        {
            c = A[j]-A[i];
            j++;
            temp=max(c,temp);           
        }
        else
        {
          i++;
          j++;
        }  
    }
    return temp;
}


int Solution::maximumGap(const vector<int> &A)
{
    vector<int> v1,v2;
    v1 = A;
    v2 = sortUsingSecondArr(v1);
    int ans = max_difference(v2);
    
    if(A.size()==1)   
        return 0;
    else
        return ans;

}
