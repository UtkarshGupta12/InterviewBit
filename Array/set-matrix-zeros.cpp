//Showing Runtime Error , Need to shorten it

// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> identifyZeroesincols(vector<vector<int>> &A)
{
    int m=A[0].size();
    int n=A.size();
    vector<int> col0(n,1);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==0)
                col0[j]=0;
        }
    }
    
    return col0;
}

vector<int> identifyZeroesinrow(vector<vector<int>> &A)
{
    int m=A[0].size();
    int n=A.size();
    vector<int> row0(m,1);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==0)
                row0[i]=0;
        }
    }
    
    return row0;
}

void setZeroes(vector<vector<int>> &A)
{
    int m=A[0].size();
    int n=A.size();    
    vector<int> row0 = identifyZeroesinrow(A);
    vector<int> col0 = identifyZeroesincols(A);    
    
    for(int i=0;i<m;i++)
    {
        if(row0[i]==0)
        {
            for(int j=0;j<n;j++)
                A[i][j] = 0;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(col0[i]==0)
        {
            for(int j=0;j<m;j++)
                A[j][i] = 0;
        }
    }    
    
}

int main() {
    // Write C++ code here
    vector<vector<int>> A(3);
    A[0].push_back(1);
    A[0].push_back(0);
    A[0].push_back(1);
    A[1].push_back(1);
    A[1].push_back(1);
    A[1].push_back(1);
    A[2].push_back(1);
    A[2].push_back(1);
    A[2].push_back(1);
    
    int m=A[0].size();
    int n=A.size();
    vector<int> row0 = identifyZeroesinrow(A);
    vector<int> col0 = identifyZeroesincols(A);
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << A[i][j] <<" ";
        cout << endl;
    }
    
    cout<<endl;
    
    for(int i=0;i<m;i++)
    {
        cout<<row0[i]<<" ";
    }
    
    cout<<endl;
    cout<<endl;
    
    for(int i=0;i<m;i++)
    {
        cout<<col0[i]<<" ";
    }
    
    cout<<endl;
    cout<<endl;
    
    setZeroes(A);
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << A[i][j] <<" ";
        cout << endl;
    }
    cout<<endl;

    return 0;
}
