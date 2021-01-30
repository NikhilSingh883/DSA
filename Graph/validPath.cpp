int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,1,-1,1,-1,0};

int dist(int x1, int y1, int x2, int y2){
    return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void dfsGraph(vector<vector<int>> &v, int start, int end, int x, int y, int r){
    if(x < 0 || y< 0 || x>=v.size() || y>=v[0].size() || dist(x,y,start,end)>r*r || v[x][y]==-1)
        return;
    v[x][y] = -1;
    for(int i=0;i<8;i++){
        dfsGraph(v, start, end, x+dx[i], y+dy[i], r);
    }
}

void dfs(int row,int col,int x,int y,vector<vector<int>>& vis){
    if(row < 0 || row > x || col < 0 || col > y || vis[row][col]!=0) return;
    
    vis[row][col] = 1;
    
    for(int i=0;i<8;i++)
        dfs(row+dx[i],col+dy[i],x,y,vis);
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
     
    vector<vector<int> > vis(A+1,vector<int>(B+1,0));
    
    vector <pair<int, int>> circles;
    for(int i=0;i<E.size();i++)
        circles.push_back({E[i], F[i]});
    sort(circles.begin(), circles.end());
    for(auto e : circles)
        dfsGraph(vis, e.first, e.second, e.first, e.second, D);
    
    dfs(0,0,A,B,vis);
    
    if(vis[A][B]==1)
        return "YES";
    return "NO";
}

