bool recur(vector<vector<bool>> &dp, const string &A, const string &B, int i, int j) {
    
    if(i < 0 && j < 0) return true;
    if(j < 0) return false;
    if(i < 0) {
        while(j >= 0) {
            if(B[j] != '*') return false;
            --j;
        }
        return true;
    }
    
    if(!dp[i][j]) return dp[i][j];
    
    bool check = false;
    
    if(B[j] == '*') check = recur(dp, A, B, i-1, j) || recur(dp, A, B, i, j-1);
    else if(B[j] == A[i] || B[j] == '?') check = recur(dp, A, B, i-1, j-1);

    return dp[i][j] = check;
} 
int Solution::isMatch(const string A, const string B) {
    
    if(A.length() == 0 || B.length() == 0) return 0;
    vector<vector<bool>> dp(A.length(), vector<bool>(B.length(), true));
    return recur(dp, A, B, A.length()-1, B.length()-1);
    
}