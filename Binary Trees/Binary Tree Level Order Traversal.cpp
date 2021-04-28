/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
        
        vector<vector<int>> lvl;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> vec;
        
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* t = q.front();
                q.pop();
                vec.push_back(t->val);
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            lvl.push_back(vec);
            vec.clear();
        }
        
        return lvl;
    
    }
};