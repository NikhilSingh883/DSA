UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node==NULL) return node;
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>  m;
    m[node] = new UndirectedGraphNode (node->label);
    queue<UndirectedGraphNode*> q;
    q.push(node);
    set<UndirectedGraphNode*> s;
    s.insert(node);
    while(!q.empty())
    {
        UndirectedGraphNode* ptr = q.front();
        q.pop();

        for(int i =0 ; i<ptr->neighbors.size(); i++)
        {
            if(m.count(ptr->neighbors[i]))
            (m[ptr]->neighbors).push_back(m[ptr->neighbors[i]]);
            else
            {
                m[ptr->neighbors[i]] = new UndirectedGraphNode (ptr->neighbors[i]->label);
                (m[ptr]->neighbors).push_back(m[ptr->neighbors[i]]);
            }
            if(s.count(ptr->neighbors[i])==0){
            q.push(ptr->neighbors[i]);
            s.insert(ptr->neighbors[i]);
            }
        }
    }
    return m[node];
}