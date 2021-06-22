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

int SubsetSumPossible(vector<int> &A,int C)
{
    sort(A.begin(),A.end());
    int n = A.size();
    int m = C;
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 && j>0) dp[i][j] = 0;
            else if(j==0) dp[i][j] = 1;
            else
            {
                if(dp[i-1][j]==1) dp[i][j] = 1; 
                else 
                {
                    if(dp[i-1][j-A[i-1]]==1) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
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

int solve(vector<int> &A)
{
    sort(A.begin(),A.end());
    int sum = accumulate(A.begin(),A.end(),0);

    if(sum%2==1) return 0;

    if(SubsetSumPossible(A,sum/2)) return 1;
    else return 0;

}

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif
  
    vector<int> A = {1,5,3};
    //vector<int> B = {1,3,4,5};
    //int C = 30;
    
    cout<<"A : ";printVec(A);cout<<endl;
    //cout<<"Weights (B) : ";printVec(B);
    //cout<<"Sum : "<<C<<endl<<endl;

    int ans = solve(A);
    cout<<endl<<"Answer : "<<ans<<endl;

    return 0;}
