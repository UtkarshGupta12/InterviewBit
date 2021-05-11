// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int N)
{
    int cols=0;
    int cole=N-1;
    int rows=0;
    int rowe=N-1;
    int count = 1;
    
    vector<vector<int>> A(N);
    for(int i=0;i<N;i++)
        A[i].resize(N);
    
    while(cols<cole && rows<rowe)
    {
        for(int i=cols;i<cole+1;i++)
        {
            A[rows][i] = count;
            count++;
        }
        rows++;
        
        for(int i=rows;i<rowe+1;i++)
        {
            A[i][cole] = count;
            count++;
        }
        cole--;
        
        for(int i=cole;i>cols-1;i--)
        {
            A[rowe][i] = count;
            count++;
        }
        rowe--;
        
        for(int i=rowe;i>rows-1;i--)
        {
            A[i][cols] = count;
            count++;
        }
        cols++;
        
    }
    
    if((N%2)!=0)
        A[(N/2)][(N/2)]=N*N;
        
    else if((N%2)==0)
        A[(N/2)][(N/2)]=N*N-1;    
    
    
    return A;
}

int main() {
    // Write C++ code here
    vector<vector<int>> A;
    int N = 3;
    A = generateMatrix(N);
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout << A[i][j] <<" ";
        cout << endl;
    }
    cout<<endl;

    return 0;
}
