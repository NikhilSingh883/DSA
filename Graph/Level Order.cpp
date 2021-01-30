void bfs(TreeNode* root,int lvl,map<int,vector<int>>& LO){
    if(root == NULL) return;
    
    LO[lvl].push_back(root->val);
    
    if(root->left) bfs(root->left,lvl+1,LO);
    if(root->right) bfs(root->right,lvl+1,LO);
    
    return;
}
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    map<int,vector<int>> LO;
    
    bfs(A,0,LO);
    vector<vector<int>> res;
    
    for(auto v:LO)
        res.push_back(v.second);
        
    return res;
}