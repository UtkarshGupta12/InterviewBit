int solve(vector<int> &A,vector<int> &B,int C)
{
    int n = A.size();
    int m = C;
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
                dp[i][j] = 0;
            else
            {  
                if(j<B[i-1])
                    dp[i][j] = dp[i-1][j];
                else 
                {
                    dp[i][j] = max(dp[i-1][j],A[i-1]+dp[i-1][j-B[i-1]]);   
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
