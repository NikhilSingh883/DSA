// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define pb push_back
#define rsz resize
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pi  pair<int,int>
#define f first
#define s second
#define pll pair<ll, ll>
#define vpl vector<pll>
#define vl vector<ll>
#define vll vector<ll, ll>
#define mp make_pair
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const ll mxN = 2e5;
const ll mod = 1e9 + 7;


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> LOT;
        
        TreeNode* temp;
        queue<TreeNode*> Q;
        
        if(!root){
            return LOT;
        }
        
        Q.push(root);
        vector<int> vec;
        
        while(!Q.empty()){
            int s = Q.size();
            
            for(int i=0;i<s;i++){
                temp = Q.front();
                Q.pop();
                
                vec.push_back(temp->val);
                
                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);

            }
            LOT.push_back(vec);
            vec.clear();
        }
        return LOT;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int height =0;
        
        return DOBT(root,&height) -1;
        
    }
    int DOBT(TreeNode* root,int *height){
        int lh=0,rh=0;
        
        if(root == NULL){ 
            *height =0;
            return 0;
        }
        
        int ld = DOBT(root->left,&lh);
        int rd = DOBT(root->right,&rh);

        
        *height = max(lh,rh)+1;
        
        return max(lh+rh+1,max(ld,rd));
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        
        TreeNode* left;
        TreeNode* right;

        left = invertTree(root->left);
        right = invertTree(root->right);
        
        root->left = right;
        root->right = left;
        return root;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        stack<TreeNode*> S;
        TreeNode* curr = root;
        
        while(!S.empty() || curr != NULL){

            while(curr != NULL){
                S.push(curr);
                curr = curr->left;
            }
            
            
            curr = S.top();
            S.pop();
            in.push_back(curr->val);
            
            curr = curr->right;
        }
        return in;
    }

    void recursiveInorderTraversal(TreeNode* root){
        if(!root) return;

        recursiveInorderTraversal(root->left);
        cout << root -> val << " ";
        recursiveInorderTraversal(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        stack<TreeNode*> S;
        TreeNode* curr = root;
        
        while(!S.empty() || curr != NULL){
            
            
            while(curr != NULL){
                pre.push_back(curr->val);
                S.push(curr);
                curr = curr->left;
            }
            
            
            curr = S.top();
            S.pop();
            
            curr = curr->right;
        }
        
        return pre;
    }
    void recursivepreorderTraversal(TreeNode* root){
        if(!root) return;

        cout << root -> val << " ";

        recursivepreorderTraversal(root->left);
        recursivepreorderTraversal(root->right);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        stack<TreeNode*> S;
        TreeNode* curr =root;
        S.push(root);
        
        while(!S.empty() && curr!=NULL){
            curr = S.top();
            S.pop();
            
            post.push_back(curr->val);
            
            if(curr->left)
                S.push(curr->left);
            
            if(curr->right)
                S.push(curr->right);
        }
        reverse(post.begin(),post.end());
        return post;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> rView;
        
        queue<TreeNode*> Q;
        Q.push(root);
        TreeNode* temp;
        int x;
        
        if(!root) return rView;
        
        while(!Q.empty()){
            int s = Q.size();
            
            for(int i=0;i<s;i++){
                temp = Q.front();
                Q.pop();
                
                x = temp->val;
                
                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);

            }
            rView.push_back(x);
        }
        
        return rView;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rView;
        
        queue<TreeNode*> Q;
        Q.push(root);
        TreeNode* temp;
        int x;

        if(!root) return rView;
        
        while(!Q.empty()){
            int s = Q.size();
            
            for(int i=0;i<s;i++){
                temp = Q.front();
                Q.pop();
                if(i==0)
                x = temp->val;
                
                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);

            }
            rView.push_back(x);
        }
        
        return rView;
    }

    void topView(Node * root) {
        if(root == NULL) return;
        
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        Node* temp;
        pair<Node*,int> d;
        while(q.size()){
            d = q.front();
            q.pop();
            
            if(mp.count(d.second)==0) mp[d.second] = d.first->data;
            
            if(d.first->left) q.push({d.first->left,d.second -1});
            
            if(d.first->right) q.push({d.first->right,d.second +1});
        }
             for(auto i=mp.begin();i!=mp.end();i++)
                cout<<i->second<<" ";
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> zigzag;
        
        TreeNode* temp;
        queue<TreeNode*> Q;
        
        if(!root){
            return zigzag;
        }
        
        Q.push(root);
        vector<int> vec;
        
        while(!Q.empty()){
            int s = Q.size();
            
            for(int i=0;i<s;i++){
                temp = Q.front();
                Q.pop();
                
                vec.push_back(temp->val);
                
                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);

            }
            zigzag.push_back(vec);
            vec.clear();
        }
        
        for(int i=1;i<zigzag.size();i+=2){
            reverse(zigzag[i].begin(),zigzag[i].end());
        }
        return zigzag;
    }

    bool isBalanced(TreeNode* root) {
        bool bal = true;
        if(root == NULL) return bal;
        int h = isBal(root,&bal);
        return bal;
    }
    
    int isBal(TreeNode* root,bool *bal){
        if(root == NULL) return 0;
        int lh = 1 + isBal(root->left,bal);
        int rh = 1 + isBal(root->right,bal);
        
        if( abs(lh-rh) > 1) *bal = false;
        
        return max(lh,rh);
    }

    vector<int> Solution::solve(TreeNode* A) {
    
            deque<TreeNode* >s;
            vector<int> v;
            s.push_front(A);
            TreeNode* root;
            
            while(!s.empty()){
                root=s.front();
                s.pop_front();
                
                v.push_back(root->val);
                if(root->left)
                s.push_back(root->left); //we have to traverse left node at end.
                if(root->right)
                s.push_front(root->right); // we have to traverse right node first.
            
            }
        return v;
    }
    void BoundaryLeft(Node *root,vector<int> &bf){
        if(!root) return;
        
        if(root->left){
            bf.push_back(root->data);
            BoundaryLeft(root->left,bf);
        }
        else if(root->right){
            bf.push_back(root->data);
            BoundaryLeft(root->right,bf);
        }
    }

    void BoundaryRight(Node *root,vector<int> &br){
        if(root == NULL) return;
        
        if(root->right){
            BoundaryRight(root->right,br);
            br.push_back(root->data);
        }
        else if(root->left){
            BoundaryRight(root->left,br);
            br.push_back(root->data);
        }
    }

    void Leaves(Node* root,vector<int> &bl){

        if (root == NULL) 
            return; 
    
        Leaves(root->left,bl); 

        if (!(root->left) && !(root->right)) 
            bl.push_back(root->data); 
            
        Leaves(root->right,bl); 
    }


    vector <int> printBoundary(Node *root)
    {
        vector<int> boundary;
        if(root == NULL) return boundary;
        
        boundary.push_back(root->data);
        
        BoundaryLeft(root->left,boundary);
        
            Leaves(root->left,boundary);
            Leaves(root->right,boundary);
                
        BoundaryRight(root->right,boundary);
        
        return boundary;
    }

    void BinaryTree2DoubleLinkedList(Node *root,Node **head){
        if(root == NULL) return;

        static Node* prev = NULL;

        BinaryTree2DoubleLinkedList(root->left,head);

        if(prev == NULL)
            *head = root;
        else{
            root->left = prev;
            prev->right = root; 
        }
        prev = root;

        BinaryTree2DoubleLinkedList(root->right,head);
    }
    void inorderutil(Node* root,vector<int> &v ){
    if(!root) return;
    inorderutil(root->left,v);
        v.push_back(root->data);
    inorderutil(root->right,v);
    return;
    }

    Node * bToDLL(Node *root)
    {
        vector<int> v;
        inorderutil(root,v);
        Node* head = newNode(v[0]);
        Node* prev=head;
        for(int i=1;i<v.size();i++){
            Node *temp=newNode(v[i]);
            temp->left=prev;
            prev->right=temp;
            prev=temp;
        }
        return head;
    }

    int sumTree(Node* node){
    if(node == NULL) return 0;
    
    int left = sumTree(node->left);
    int right = sumTree(node->right);
    int temp = node->data;
    
     node->data = left + right;
     
     return left + right + temp;
    }

    void toSumTree(Node *node)
    {
        if(node == NULL) return ;
        
        int sum = sumTree(node);
    }



    int findIndex(int arr[], int start, int target)
    {
        int i=0;
        while( arr[start+i] != target ) i++;
        return i;
    }

    Node* buildUtil(int inorder[], int preorder[], int inStart, int preStart, int n)
    {
        if(n==0) return NULL;
        
        Node* ret = new Node( preorder[preStart] );
        
        int i = findIndex( inorder, inStart, preorder[preStart] );
        
        ret->left = buildUtil( inorder, preorder, inStart, preStart+1, i );
        ret->right = buildUtil( inorder, preorder, inStart+i+1, preStart+i+1, n-i-1 );
        
        return ret;
    }

    Node *buildTree(int inorder[], int preorder[], int n)
    {
        return buildUtil(inorder, preorder, 0, 0, n);
    }




    void inorder(int a[], std::vector<int> &v, 
                        int n, int index)
    {
    if(index >= n)
        return;
    inorder(a, v, n, 2 * index + 1);
     
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
    }

    int minSwaps(int arr[], int n){
        pair<int, int> arrPos[n];
        for (int i = 0; i < n; i++)
        {
            arrPos[i].first = arr[i];
            arrPos[i].second = i;
        }

        sort(arrPos, arrPos + n);
        vector<bool> vis(n, false);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] || arrPos[i].second == i)
                continue;
            int cycle_size = 0;
            int j = i;
            while (!vis[j])
            {
                vis[j] = 1;
    
                j = arrPos[j].second;
                cycle_size++;
            }

            if (cycle_size > 0)
            {
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }

    // sum tree or not 

            int sum( Node *root)
        {
            if (root == NULL)
                return 0;
            
            return sum(root->left) + root->data +
                sum(root->right);
        }

        bool isSumTree( Node* node)
        {
            int ls, rs;
        
            // If node is NULL or it's a leaf
            // node then return true 
            if (node == NULL ||
            (node->left == NULL && 
                node->right == NULL))
                return 1;

        ls = sum(node->left);
        rs = sum(node->right);

            if ((node->data == ls + rs) &&
                isSumTree(node->left) &&
                isSumTree(node->right))
                return 1;
        
        return 0;
        }

    // dublicate sub tree

    string dubSubUtil(Node *root){
        string s = "";
        
        if(root == NULL)
            return s + "#";
            
        string lstr = dubSubUtil(root->left);
        if(lstr == s)
            return "";
            
        string rstr = dubSubUtil(root->right);
        if(rstr == s)
            return "";
        s = s + root->data + lstr + rstr;
        
        if(s.size() > 3)
            if(st.find(s)!=st.end())
                return "";
                
        st.insert(s);
        
        return s;
    }    
    bool dupSub(Node *root)
    {
        st.clear();
        string str = dubSubUtil(root); 
    
        return (str=="") ?  1: 0; 
    }

    // sum of the longest branch

    void sumOfLongRootToLeafPathUtil(Node* root,int sum,int len,int &maxLen,int &maxSum){
        
        if (!root) { 
    
            if (maxLen < len) { 
                maxLen = len; 
                maxSum = sum; 
            } else if (maxLen == len && maxSum < sum) 
                maxSum = sum; 
            return; 
        } 
    
        // recur for left subtree 
        sumOfLongRootToLeafPathUtil(root->left, sum + root->data, 
                                len + 1, maxLen, maxSum); 
    
        // recur for right subtree 
        sumOfLongRootToLeafPathUtil(root->right, sum + root->data, 
                                len + 1, maxLen, maxSum);
    }



    int sumOfLongRootToLeafPath(Node* root)
    {
        if(!root) return 0;
        
        int maxSum = INT_MIN,maxlen =0;
        
        sumOfLongRootToLeafPathUtil(root,0,0,maxlen,maxSum);
        
        return maxSum;
    }

    // largest subtree sum

    int findLargestSubtreeSumUtil(Node* root, int& ans) 
    { 
        if (root == NULL)      
            return 0; 
        
        int currSum = root->key +  
        findLargestSubtreeSumUtil(root->left, ans) 
        + findLargestSubtreeSumUtil(root->right, ans); 
    
        ans = max(ans, currSum); 
    
        return currSum; 
    } 
    
    int findLargestSubtreeSum(Node* root) 
    { 
        if (root == NULL)      
            return 0; 
        
        int ans = INT_MIN; 

        findLargestSubtreeSumUtil(root, ans); 
    
        return ans; 
    }

    // print all k sum paths
    void printVector(const vector<int>& v, int i){ 
    for (int j=i; j<v.size(); j++) 
        cout << v[j] << " "; 
    cout << endl; 
    }

    void printKPathUtil(Node *root, vector<int>& path,int k) { 
        if (!root) 
            return; 

        path.push_back(root->data); 
 
        printKPathUtil(root->left, path, k); 
    
        printKPathUtil(root->right, path, k); 

        int f = 0; 
        for (int j=path.size()-1; j>=0; j--) 
        { 
            f += path[j]; 
    
            if (f == k) 
                printVector(path, j); 
        }
    
        path.pop_back(); 
    } 
    
    void printKPath(Node *root, int k) { 
        vector<int> path; 
        printKPathUtil(root, path, k); 
    }

    // lowest common ancester
    bool findPath(Node* root,vector<Node*> &path,int k){
        if(root == NULL) return false;
        
        
        path.push_back(root);
        
        if(root->data == k) 
            return true;
        
        if((root->left && findPath(root->left,path,k)) || (root->right && findPath(root->right,path,k)))
            return true;
            
        path.pop_back();
        
        return false;
    }

    Node* lca(Node* root ,int n1 ,int n2 )
    {
    vector<Node*> path1,path2;
    
    if( !findPath(root,path1,n1) || !findPath(root,path2,n2))
        return NULL;
        
        int i;
        for( i=0;i< path1.size() && i < path2.size() ;i++)
            if(path1[i]->data != path2[i]->data) break;
        
        
        return path1[i-1];
    }

    // distance btwn two nodes

    int findDist(Node* root, int a, int b) {
        vector<Node*> path1,path2;
    
    if( !findPath(root,path1,a) || !findPath(root,path2,b))
        return NULL;
        
        int i;
        for( i=0;i< path1.size() && i < path2.size() ;i++)
            if(path1[i]->data != path2[i]->data) break;
        
        
        return path1.size() + path2.size() - 2 * i;
    }

    // two trees isomorphic or not

    bool isIsomorphic(node* n1, node *n2) { 
        if (n1 == NULL && n2 == NULL) 
            return true; 
        
        if (n1 == NULL || n2 == NULL) 
            return false; 
        
        if (n1->data != n2->data) 
            return false; 

        return 
        (isIsomorphic(n1->left,n2->left) && isIsomorphic(n1->right,n2->right))|| 
        (isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left)); 
    }
};