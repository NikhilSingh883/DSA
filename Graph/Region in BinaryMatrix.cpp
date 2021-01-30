int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,1,-1,1,-1,0};

void myfun(int i,int j,vector<vector<int>> &A,int &cnt){
    if(i<0 || j<0 || i>=A.size() || j>=A[0].size() || A[i][j]==0 )
        return;
        cnt++;
        
    A[i][j]=0;
        
    for(int x=0;x<8;x++)
        myfun(i+dx[x],j+dy[x],A,cnt);
}

int Solution::solve(vector<vector<int> > &A) {
    int mx = INT_MIN;
    int cnt =0 ;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]==1){
                cnt = 0;
                myfun(i,j,A,cnt);
                mx = max(cnt,mx);
            }
        }
    }
    return mx;
}