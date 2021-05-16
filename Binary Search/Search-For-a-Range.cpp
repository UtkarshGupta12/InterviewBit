#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int FindFirst(const vector<int> &A,int x)
{
    int low=0,high=A.size()-1;
    int result = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(A[mid]==x)
        {
            result = mid;
            high = mid-1;
                
        }
        else if(x<A[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return result;
}

int FindLast(const vector<int> &A,int x)
{
    int low=0,high=A.size()-1;
    int result = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(A[mid]==x)
        {
            result = mid;
            low = mid+1;
                
        }
        else if(x<A[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return result;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) 
{
    int First,Last;
    First = FindFirst(A,B);
    Last = FindLast(A,B);
    
    vector<int> ans;
    ans.push_back(First);
    ans.push_back(Last);
    
    return ans;
}
