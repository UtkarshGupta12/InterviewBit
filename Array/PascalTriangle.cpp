// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int A)
{
    vector<vector<int>> v(A);
    for(int i=0;i<A;i++)
    {
        v[i].resize(i+1);
        v[i][0] = v[i][i] = 1;
        for(int j=1;j<i;j++)
        {
            v[i][j] = v[i-1][j-1]+v[i-1][j];
        }
    }
    return v;
}

int main() {
    // Write C++ code here
    int A = 4;
    vector<vector<int>> k = solve(A);
    for(int i=0;i<A;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cout << k[i][j] <<" ";
        }
        
        cout << endl;
    }
    cout<<endl;

    return 0;
}
