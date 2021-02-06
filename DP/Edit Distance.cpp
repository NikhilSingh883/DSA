int dp[1006][1006];

int lcs(string a,string b,int n,int m){
    if(n<=0 || m<=0) return 0;
    
    if(dp[n][m]!=-1) return dp[n][m];
    
    if(a[n-1]==b[m-1])
        return dp[n][m] = 1 + lcs(a,b,n-1,m-1);
        
    return dp[n][m] = max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
}

int Solution::minDistance(string A, string B) {
    
    memset(dp,INT_MAX,sizeof dp);
    int n = A.size(),m=B.size(),rep=0,ins=0,del=0;

    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else if(A[i-1]==B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }


    
    return dp[n][m];
     
}
