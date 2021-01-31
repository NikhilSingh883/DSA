#define tp tuple<int,int,int>

bool isSafe(int i,int j,int upx,int upy)
{
    return (i>=0)&&(i<upx)&&(j>=0)&&(j<upy);
}
int Solution::solve(int A, int B, vector<string> &C) {
    deque<tp> q;
    vector<vector<bool>> visited(A,vector<bool> (B,false));
    q.push_front({0,0,0});
    unordered_map<char,pair<int,int>> steps;
    steps.insert({'U',make_pair(-1,0)}),steps.insert({'D',make_pair(1,0)}),steps.insert({'L',make_pair(0,-1)}),steps.insert({'R',make_pair(0,1)});
    
    while(!q.empty())
    {
        auto [cost,i,j]=q.front();
        q.pop_front();
        visited[i][j]=true;
        if(i==A-1&&j==B-1) return cost;
        for(auto x : steps)
        {
            int n_x=i+x.second.first,n_y=j+x.second.second;
            if(isSafe(n_x,n_y,A,B)&&!visited[n_x][n_y])
            {
                if(C[i][j]==x.first) q.push_front({cost,n_x,n_y});
                else q.push_back({cost+1,n_x,n_y});
            }
        }
    }
    return -1;
}