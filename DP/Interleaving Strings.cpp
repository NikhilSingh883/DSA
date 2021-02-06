int dp[1006][1006];

int lcs(string a,string b,int n,int m){
    if(n<=0 || m<=0) return 0;
    
    if(dp[n][m]!=-1) return dp[n][m];
    
    if(a[n-1]==b[m-1])
        return dp[n][m] = 1 + lcs(a,b,n-1,m-1);
        
    return dp[n][m] = max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
}

int Solution::isInterleave(string a, string b, string c) {
    
    memset(dp,-1,sizeof dp);
    int ac = lcs(a,c,a.size(),c.size());
    memset(dp,-1,sizeof dp);
    int bc = lcs(b,c,b.size(),c.size());
    
    return ac == a.size() && bc == b.size() && ac + bc == c.size();
}
