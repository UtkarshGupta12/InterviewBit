// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int maxArr(vector<int> &A)
{
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        max1 = max(max1,A[i]+i);
        max2 = max(max2,A[i]-i);
        min1 = min(min1,A[i]+i);
        min2 = min(min2,A[i]-i);
    }
    
    return max(max1 - min1,max2 - min2);
}

int main() {
    // Write C++ code here
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(-1);

    
    cout<<"[ ";
    for(int i=0;i<A.size();i++)
        cout << A.at(i)<<" ";
    
    cout << "]"<<endl;
    
    cout << maxArr(A)<<endl;
    
    return 0;
}
