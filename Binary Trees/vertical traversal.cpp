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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> m;
        // if tree is null return empty vector
		if(!root){
            return m;
        }
		// map for storing the column no and vector of pair which stores node values 
		// and row in which it is present
        map<int, vector<pair<int,int>>> mp;
		// curr col and row
        int hd=0,row=1;
		
		// a queue which stores a pair of Node and pair of current row and col
        queue<pair<TreeNode*,pair<int,int>>> q;
		// push the root node with its column as 0 and row as 1
        q.push(make_pair(root,make_pair(row,hd)));
		// Level Order Traversal(BFS)
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            row=q.front().second.first;
            int x=q.front().second.second;
            q.pop();
            mp[x].push_back(make_pair(row,temp->val));
			// if left child is present , push it into the queue
            if(temp->left){
                q.push(make_pair(temp->left,make_pair(row+1,x-1)));
            }
			// if right child is there , push it into the queue
            if(temp->right){
                q.push(make_pair(temp->right,make_pair(row+1,x+1)));
            }
        }
		// iterating the map
        for(auto x:mp){
            vector<int> v;
			// sorting the vector of pair as we have to get minimum first on same level
            sort(x.second.begin(),x.second.end());
            for(int i=0;i<x.second.size();i++){
                v.push_back(x.second[i].second);   
            }
            m.push_back(v);
        }
        return m;
        
    }
};