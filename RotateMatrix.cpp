#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void mirrorLEFT(vector<vector<int>> &A)
{
    int N = A.size();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N/2;j++)
        {
            swap(A[i][j],A[i][N-j-1]);
        }
    }
}

void mirrorDIAGONAL(vector<vector<int>> &A)
{
    int N = A.size();
    for(int i=0;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
            swap(A[i][j],A[j][i]);
        }
    }
}

void rotate(vector<vector<int>> &A)
{
    mirrorDIAGONAL(A);
    mirrorLEFT(A);
}

int main() 
{
    // Write C++ code here
    vector<vector<int>> A(3);
    A[0].push_back(1);
    A[0].push_back(2);
    A[0].push_back(3);
    A[1].push_back(4);
    A[1].push_back(5);
    A[1].push_back(6);
    A[2].push_back(7);
    A[2].push_back(8);
    A[2].push_back(9);
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << A[i][j] <<" ";
        
        cout << endl;        
    }
    
    cout<<endl;
    
    mirrorDIAGONAL(A);
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << A[i][j] <<" ";
        
        cout << endl;        
    }
    
    cout<<endl;    
    
    mirrorLEFT(A);
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << A[i][j] <<" ";
        
        cout << endl;        
    }
    
    cout<<endl;  
    
    rotate(A);
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << A[i][j] <<" ";
        
        cout << endl;        
    }
    
    cout<<endl;      

    return 0;
}
