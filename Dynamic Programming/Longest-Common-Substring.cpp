int solve(string &A,string &B)
{
    int n = A.size();
    int m = B.size();
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
                dp[i][j] = 0;
            else
            {  
                if(A[i-1]==B[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
            }    
        }
    }

    //Find max value in dp
    int max_res = INT_MIN;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            max_res = max(max_res,dp[i][j]);
        
    

    //Printing Matrix
    for (int i = 0; i <=n; i++){
        for (int j = 0; j <=m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;}
    
    return max_res;
}
