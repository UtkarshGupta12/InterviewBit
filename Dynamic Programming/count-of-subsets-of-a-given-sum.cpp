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
using namespace std;

int CountofSubsets(vector<int> &A,int C)
{
    sort(A.begin(),A.end());
    int n = A.size();
    int m = C;
    int dp[n+1][m+1];
    dp[0][0] = 1;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 && j>0) dp[i][j] = 0;
            else if(j==0) dp[i][j] = 1;

            else
            {
                if(j<A[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j]+dp[i-1][j-A[i-1]];
            }        
        }
    }    

    //Printing Matrix
    for (int i = 0; i <=n; i++){
        for (int j = 0; j <=m; j++)
        {
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
  
    vector<int> A = {1,1,1,1};
    //vector<int> B = {1,3,4,5};
    int C = 1;
    
    cout<<"A : ";printVec(A);
    //cout<<"Weights (B) : ";printVec(B);
    cout<<"Sum : "<<C<<endl<<endl;

    int ans = CountofSubsets(A,C);
    cout<<endl<<"Answer : "<<ans<<endl;

    return 0;}
