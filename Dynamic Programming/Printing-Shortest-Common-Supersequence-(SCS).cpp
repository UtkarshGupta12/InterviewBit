string solve(string A,string B)
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
                if(A[i-1]==B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
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

    //Extracting the answer
    string res = "";  
    int i = n;
    int j = m;

    while(i>0 && j>0)
    {
        if(A[i-1]==B[j-1])
        {
            res += A[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>=dp[i][j-1])
            {
                i--;
                res += A[i];
            }
            else 
            {
                j--;
                res += B[j];            
            }
        }
    }

    reverse(res.begin(),res.end());
    return res;
}
