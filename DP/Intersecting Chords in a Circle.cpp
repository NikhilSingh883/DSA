int Solution::chordCnt(int A) {
    long long int mod = 1000000007;
    long long int dp[A+1];
    dp[0] = 1;
    
    for(int i=1;i<=A;i++){
        dp[0]=0;
        for(int j=0;j<i;j++){
            dp[i] = (dp[i]%mod + (dp[j]%mod*dp[i-j-1]%mod)%mod)%mod;
        }
    }
    return (dp[A]+mod)%mod;
}