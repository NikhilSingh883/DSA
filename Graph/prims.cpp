int Solution::solve(int A, vector<vector<int> > &B) {
    using PII = pair<int,int>;
    vector<vector<PII>> adj(A+1);
    
    for(auto edge:B){
        int weight = edge[2], u = edge[0], v = edge[1];
        adj[v].push_back({u,weight});
        adj[u].push_back({v,weight});
    }
    
    priority_queue<PII,vector<PII>,greater<PII>> q;
    vector<bool> visited(A+1,false);
    q.push({0,1}); // cost from 1 to itself is 0;
    
    int cost = 0;
    while(!q.empty()){
        PII ele = q.top();
        q.pop();
        int u = ele.second;
        int weight = ele.first;
        //check if this node is not already included in MST
        if(!visited[u]){
            cost += weight;
            visited[u] = true;
            for(auto v: adj[u]){
                if(!visited[v.first]){
                    q.push({v.second , v.first });
                }
            }
        }
    }
    return cost;
}