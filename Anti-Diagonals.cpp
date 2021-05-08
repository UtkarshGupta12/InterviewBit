// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonal(vector<vector<int>> &A)
{
    int N = A[0].size();
    vector<vector<int>> v(2*N-1);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i+1;j++)
        {
           for(int k=0;k<i+1;k++)
           {
              if(j+k==i)
                v[i].push_back(A[j][k]);
           }
        }
    }
    
    for(int i=N;i<2*N-1;i++)
    {
        for(int j=0;j<N;j++)
        {
           for(int k=0;k<N;k++)
           {
              if(j+k==i)
                v[i].push_back(A[j][k]);
           }
        }
    }
    
    return v;
}

int main() {
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
        {
            cout << A[i][j] <<" ";
        }
        cout << endl;
    }
    cout<<endl;
    
    vector<vector<int>> v;
    v = diagonal(A);
    
    cout << v[0][0] << endl;
    cout << v[1][0] <<" "<< v[1][1] << endl;
    cout << v[2][0] <<" "<< v[2][1] <<" "<< v[2][2] << endl;
    cout << v[3][0] <<" "<< v[3][1] << endl;
    cout << v[4][0] << endl;
    

    return 0;
}
