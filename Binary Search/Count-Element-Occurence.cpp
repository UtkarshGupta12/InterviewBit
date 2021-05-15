//   Time Complexity of log(N)
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}

int FindFirst(vector<int> &A,int x)
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

int FindLast(vector<int> &A,int x)
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

int FindCount(vector<int> &A,int x)
{
    int First,Last;
    First = FindFirst(A,x);
    Last = FindLast(A,x);
    
    if(Last >= 0 && First >= 0)
        return(Last-First+1);
    else
        return 0;
}

int main()
{
    // 1 1 3 3 5 5 5 5 5 9 9 11
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    A.push_back(3);
    A.push_back(3);
    A.push_back(5);
    A.push_back(5);
    A.push_back(5);
    A.push_back(5);
    A.push_back(5);
    A.push_back(9);
    A.push_back(9);
    A.push_back(11);
    
    printVec(A);
    
    int sol = FindCount(A,5);
    
    cout<< sol << endl; 
}
