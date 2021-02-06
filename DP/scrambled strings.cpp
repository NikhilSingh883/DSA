unordered_map<string,bool> dp;

bool isAnagram( string s1, string s2 ){
    sort( s1.begin(), s1.end() );
    sort( s2.begin(), s2.end() );
    if( s1 != s2 )
        return false;
    else 
        return true;
}

bool solve(string a, string b) {
    
    if(a.compare(b)==0)
        return true;
    
    if(!isAnagram(a,b))
        return false;
    
    if(a.length()<=1)
        return false;
    
    string key = a;
    key+='_';
    key+=b;
    
    if(dp.find(key)!=dp.end()) return dp[key];
    
    bool flag = false;
    int n = a.length();
    for(int i=1;i<n;i++){
        bool cond_1 = (solve(a.substr(0, i), b.substr(n-i, i))) && 
           (solve(a.substr(i, n-i), b.substr(0, n-i)));
        
        bool cond_2 = (solve(a.substr(0, i), b.substr(0, i))) && 
           (solve(a.substr(i, n-i), b.substr(i, n-i)));
        
        if  (cond_1 || cond_2){
            flag = true;
            return flag;
        }
    }
    
    return dp[key] = flag;
}

int Solution::isScramble(const string A, const string B) {
    
    dp.clear();
    return solve(A,B);
}
