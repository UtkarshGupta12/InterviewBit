#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <stack>
#include <cmath>
#include <iomanip>
#include <map>
#include <iterator>
#include <string.h>
#define M 1000000007
#define INF INT_MAX-1
using namespace std;

int solve(vector<int> &A,int C)
{
    int n = A.size();
    int m = C;
    int dp[n+1][m+1];

    //Initialising dp
    for(int j=0;j<=m;j++)
        dp[0][j] = INF;
    for(int i=1;i<=n;i++)
        dp[i][0] = 0;
    for(int j=1;j<=m;j++)
    {
        if(dp[1][j]%A[0]==0) dp[1][j] = j/A[0];
        else dp[1][j] = INF;}

    //Preparing Recursive Code
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j>=A[i-1]) dp[i][j] = min(dp[i][j-A[i-1]]+1,dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    //Printing Matrix
    for (int i = 0; i <=n; i++){
        for (int j = 0; j <=m; j++)
        {
            if(dp[i][j]==INF) 
                cout << "I" << " ";
            else
                cout << dp[i][j] << " ";
        }
        cout << endl;}
    
    return dp[n][m];
}

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif
  
    vector<int> A = {1,2,3};
    vector<int> B = {1,5,8,9,10,17,17,20};
    int C = 5;
    
    cout<<"Coins : ";printVec(A);
    //cout<<"Price (B)  : ";printVec(B);
    cout<<"Sum : "<<C<<endl<<endl;

    int ans = solve(A,C);
    cout<<endl<<"Answer : "<<ans<<endl;

    return 0;}
