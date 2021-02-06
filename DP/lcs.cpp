int dp[1006][1006];

int lcs(string a,string b,int n,int m){
    if(n<=0 || m<=0) return 0;
    
    if(dp[n][m]!=-1) return dp[n][m];
    
    if(a[n-1]==b[m-1])
        return dp[n][m] = 1 + lcs(a,b,n-1,m-1);
        
    return dp[n][m] = max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
}

int Solution::solve(string A, string B) {
    
    memset(dp,-1,sizeof dp);
    int n = A.size(),m=B.size();
    for(int i=0;i<n;i++) dp[i][0] = 0;
    for(int i=0;i<m;i++) dp[0][i] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    return  dp[n][m];
}
