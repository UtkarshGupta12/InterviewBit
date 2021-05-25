#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printPair(vector<pair<int,int>> &pair1)
{
    for(int i = 0; i < pair1.size(); i++)
         cout <<"["<< pair1[i].first << "," << pair1[i].second<<"],";

    cout << endl;  }

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

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}


int main()
{
    vector<int> A;
    A.push_back(5);
    A.push_back(5);
    A.push_back(2);
    A.push_back(5);
    A.push_back(8);
    
    printVec(A);
    
    int sol = solve(A);
    
    cout<< sol << endl; 
}
