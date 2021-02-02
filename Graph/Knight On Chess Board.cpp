    int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};

bool isSafe(int x,int y ,int n,int m){
    if(x<1 || y <1 || x >n || y > m) 
        return false;
    return true;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    int row =1 ,col=1;
    tuple <int, int, int> move;
    queue<tuple <int, int, int>> q;
    vector<vector<int>> vis(A+1,vector<int>(B+1,0));
    
    q.push(make_tuple(0,C,D));
    
    while(!q.empty()){
        auto [cnt,x,y] = q.front();
        q.pop();
        
        if(x==E && y == F) return cnt;
        
        for(int i=0;i<8;i++)
            if(isSafe(x+dx[i],y+dy[i],A,B) && !vis[x+dx[i]][y+dy[i]]){
                vis[x+dx[i]][y+dy[i]] = true;
                q.push(make_tuple(cnt+1,x+dx[i],y+dy[i]));
            }
    }
    
    return -1;
}
