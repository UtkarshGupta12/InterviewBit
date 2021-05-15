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

int FindRotationCount(vector<int> &A)
{
   int low = 0,high = A.size()-1;
   int n = A.size();
   while(low<=high)
   {
        if(A[low]<=A[high])
            return low;//CASE 1
        int mid = (low+high)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        
        if(A[mid] <= A[next] && A[mid] <= A[prev])
            return mid; // CASE 2
            
        else if(A[mid] <= A[high]) 
            high = mid -1; // CASE 3
            
        else if(A[mid] >= A[low]) 
            low = mid+1; // CASE 4
   }
   return -1;
}

int main()
{
    // 11 12 15 18 2 5 6 8
    vector<int> A;
    A.push_back(11);
    A.push_back(12);
    A.push_back(15);
    A.push_back(18);
    A.push_back(2);
    A.push_back(5);
    A.push_back(6);
    A.push_back(8);

    printVec(A);
    
    int sol = FindRotationCount(A);
    
    cout<< sol << endl; 
}
