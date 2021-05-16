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

void printMatrix(vector<vector<int>> &mat)  
{
    int nrows = mat.size();
    int ncols = mat[0].size();
    for(int i=0;i<nrows;i++)
    {
        for(int j=0;j<ncols;j++)
            cout << mat[i][j] << " ";
        cout << endl;        
    }        
}

int searchInsert(vector<int> &A, int B) 
{
    int low = 0, high = A.size()-1;

    while(low <= high) 
    {
        int mid = (high + low) / 2;
        cout <<"low = "<<low<<" , high = "<< high<<" , mid = "<< mid << endl;
        
        if(A[mid]==B)
            return mid;
        else if(A[mid] > B && A[mid-1] < B)
            return mid;
        else if(A[high] < B)
            return high+1;
        else if(A[low] > B)
            return 0;
        else if(A[mid] < B ) 
            low = mid + 1;
        else
            high = mid - 1;
        
    }
    return 0;
}

int main()
{
    //[1,3,5,6], 5 → 2
    //[1,3,5,6], 2 → 1
    //[1,3,5,6], 7 → 4
    //[1,3,5,6], 0 → 0

    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(5);
    A.push_back(7);

    printVec(A);
    
    int n = searchInsert(A,1);
    cout << "Position is = "<< n << endl;
    
    //cout<< sol << endl; 
}
