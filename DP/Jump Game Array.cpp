int Solution::canJump(vector<int> &A) {
    int maxi = 0,n = A.size(),i;
    for(i = 0;i<n and i<=maxi;i++)
            maxi = max(A[i]+i,maxi);
    return i==n;
}