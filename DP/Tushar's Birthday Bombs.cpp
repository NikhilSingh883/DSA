vector<int> Solution::solve(int R, vector<int> &p) {
        int n = (int)p.size();
    vector<int> dp(R + 1, -1);
    vector<int> back(R + 1);

    back[0] = 0;
    for (int r = 0; r <= R; r++) {
        for (int i = 0; i < n; i++) {
            if (r >= p[i] && dp[r] < dp[r - p[i]] + 1) {
                dp[r] = dp[r - p[i]] + 1;
                back[r] = i;
            }
        }
    }

    vector<int> ans;
    int r = R;
    while (r >= 0 && (r - p[back[r]]) >= 0) {
        ans.push_back(back[r]);
        r = r - p[back[r]];
    }
    return ans;
}
