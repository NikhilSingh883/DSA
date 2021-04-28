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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        unordered_map<TreeNode*,int> cnt;
        stack<TreeNode*> S;
        S.push(root);
        
        while(!S.empty()){
            TreeNode* curr = S.top();
            
            if(curr == NULL) {
                S.pop();
                continue;
            }
            else if(cnt[curr] == 0){
                ans.push_back(curr->val);
            }
            else if(cnt[curr]==1){
                S.push(curr->left);
            }
            else if(cnt[curr]==2){
                S.push(curr->right);
            }
            else S.pop();
            
            cnt[curr]++;
        }
        
        return ans;
    }

// stack appraoch

    vector<int> preorderTraversal(TreeNode* root) {
        
        if(root==NULL) return {};
        vector<int> pre;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode *temp = st.top();
            st.pop();
            pre.push_back(temp->val);
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        
        return pre;
    }
};