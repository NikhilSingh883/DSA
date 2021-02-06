//Distinct Subsequences
int dp[701][701];

int numDist(int i,int j,int n,int m,string a,string b){
    
    if(j==m) return 1;
    if(i>=n || j>m) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int ans =0;
    if(a[i]==b[j])
        ans += numDist(i+1,j+1,n,m,a,b);
    ans += numDist(i+1,j,n,m,a,b);
    
    return dp[i][j] = ans;
}

int Solution::numDistinct(string A, string B) {
    
    int n = A.length(),m=B.length();
    memset(dp,-1,sizeof dp);
    return numDist(0,0,n,m,A,B);
}
