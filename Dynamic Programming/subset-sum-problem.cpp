int Solution::solve(vector<int> &A,int C)
{
    if(A.empty()&&C==0) return 1;
    
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

    return dp[n][m];
}
