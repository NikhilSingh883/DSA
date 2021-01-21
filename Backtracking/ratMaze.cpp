// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> findPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5


bool isSafe(int i,int j,int n,int m[][MAX],bool vis[][MAX]){
    if(i==-1 || i==n || j==-1 || j==n || vis[i][j] || m[i][j]==0)
        return false;
    return true;
}

void findPathUtil(vector<string> &paths,string s,int i,int j,int n,int m[MAX][MAX],bool vis[][MAX]){
    if(i==-1 || i==n || j==-1 || j==n || vis[i][j] || m[i][j]==0)
        return;

    
    if(i==n-1 && j==n-1){
        paths.push_back(s);
        return;
    }
    vis[i][j] = true;
    
    if(isSafe(i-1,j,n,m,vis)){
    findPathUtil(paths,s+'U',i-1,j,n,m,vis);
    }
    if(isSafe(i+1,j,n,m,vis)){

    findPathUtil(paths,s+'D',i+1,j,n,m,vis);

    }
    if(isSafe(i,j-1,n,m,vis)){
    findPathUtil(paths,s+'L',i,j-1,n,m,vis);
    }
    if(isSafe(i,j+1,n,m,vis)){
    findPathUtil(paths,s+'R',i,j+1,n,m,vis);
    }
    
    vis[i][j] = false;
}

vector<string> findPath(int m[MAX][MAX], int n) {
    // Your code goes here
    vector<string> paths;
    bool vis[MAX][MAX];
    string st;
    memset(vis,false,sizeof vis);
    
    findPathUtil(paths,st,0,0,n,m,vis);
    sort(paths.begin(),paths.end());
    return paths;
}
