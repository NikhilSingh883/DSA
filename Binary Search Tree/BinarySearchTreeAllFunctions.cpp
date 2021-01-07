
// search an element inside BST
struct node* search(struct node* root, int key) 
{ 
    if (root == NULL || root->key == key) 
       return root; 
     
    if (root->key < key) 
       return search(root->right, key); 
  
    return search(root->left, key); 
}

// insert a node in BST
Node* insert(Node* root, int key)
{
    // Your code here
    if(root == NULL){
        Node* temp = new Node(key);
        root = temp;
        return temp;    
    }
        
    if(root->data > key)
        root->left =  insert(root->left,key);
    else if(root->data < key)
        root->right =  insert(root->right,key);
    
    return root;
}

// delete node at BST

TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val>key) root->left=deleteNode (root->left, key);
        else if (root->val<key) root->right=deleteNode (root->right, key);

        else {  
            if (!root->left && !root->right) {
                delete(root);
                return NULL;
            }
            else if (!root->left || !root->right) {
                TreeNode* successor=root->left?root->left: root->right;
                delete(root);
                return successor;
            }
            else {
                TreeNode* successor=findSuccessor (root->right);
                root->val=successor->val;
                root->right = deleteNode (root->right, successor->val);
            }
        }
        return root;
    }
TreeNode* findSuccessor (TreeNode* root) {
        while (root->left) root=root->left;
        return root;
}

// Predecessor and Successor

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if (root == NULL)  return ; 
 
    if (root->key == key) 
    { 
        if (root->left != NULL) 
        { 
            Node* tmp = root->left; 
            while (tmp->right) 
                tmp = tmp->right; 
            pre = tmp ; 
        } 
 
        if (root->right != NULL) 
        { 
            Node* tmp = root->right ; 
            while (tmp->left) 
                tmp = tmp->left ; 
            suc = tmp ; 
        } 
        return ; 
    } 
    if (root->key > key) 
    { 
        suc = root ; 
        findPreSuc(root->left, pre, suc, key) ; 
    } 
    else 
    { 
        pre = root ; 
        findPreSuc(root->right, pre, suc, key) ; 
    } 
    
}

// Populate Inorder Successor for all nodes
void inorder(struct node* p,vector<struct node*> &vec){
    if(!p) return;
    
    inorder(p->left,vec);
    vec.push_back(p);
    inorder(p->right,vec);
}

void populateNext(struct node* p)
{

    vector<struct node*> in;
    inorder(p,in);
    
    struct node* tmp = new node(-1);
    
    for(int i=0;i<in.size()-1;i++){
        in[i]->next = in[i+1];
    }
    // in[in.size()-1]->next = tmp;
}

// LCA of BST

Node* LCA(Node *root, int n1, int n2)
{
    if(!root) return root;
    
    if(root->data < n1 && root->data < n2)    
        return LCA(root->right,n1,n2);
    
    if(root->data > n1 && root->data > n2)    
        return LCA(root->left,n1,n2);
        
    return root;
}

// binary tree to BST

void pre(Node* root,vector<int> &v){
    if(!root) return;
    v.push_back(root->data);
    if(root->left)
    pre(root->left,v);
    if(root->right)
    pre(root->right,v);
}
void inorder(Node* root,vector<int> v,int &index){
    if(!root) return;
    if(root->left)
    inorder(root->left,v,index);
    root->data=v[index++];
    if(root->right)
    inorder(root->right,v,index);
}
Node *binaryTreeToBST (Node *root)
{
    if(!root) return root;
    vector<int> v;
    int index=0;
    pre(root,v);
    sort(v.begin(),v.end());
    inorder(root,v,index);
    return root;
}

// BST from preorder

    TreeNode* build(vector<int> pre,int &i,int min,int max){
        TreeNode* root = NULL;
        
        if(pre[i]>min && pre[i]<max){
            root = new TreeNode(pre[i]);
            i++;
            
            if(i<pre.size())
                root->left = build(pre,i,min,root->val);
            if(i<pre.size())
                root->right = build(pre,i,root->val,max);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MIN,INT_MAX);
    }

// balance BST
    void storeTree(TreeNode* root,vector<TreeNode*> &t){
        if(!root) return;
        
        storeTree(root->left,t);
        t.push_back(root);
        storeTree(root->right,t);
    }
    TreeNode* balanceTree(vector<TreeNode*> tree,int st,int en){
        
        if(st > en) return NULL;
        
        int mid = (st+en)/2;
        
        TreeNode* root =  tree[mid];
        
        root->left = balanceTree(tree,st,mid-1);
        root->right = balanceTree(tree,mid+1,en);
        
        return root;
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> tree;
        storeTree(root,tree);
        int n = tree.size();
        return balanceTree(tree,0,n-1);
    }

// merge two BST

    void storeInorder(TreeNode* root,vector<int> &t){
        if(!root) return;
        
        storeInorder(root->left,t);
        t.push_back(root->data);
        storeInorder(root->right,t);
    }
void merge(vector<int> a,vector<int> b,vector<int> R,int m,int n){
    int i=0,j=0;

    while(i<m && j<n){
        if(a[i] < b[j]){
            R.push_back(a[i]);
            i++;
        }
        else {
            R.push_back(b[j]);
            j++;
        }
    }

    while(i<m){
        R.push_back(a[i]);
        i++;
    }
    while(j<n){
        R.push_back(b[j]);
        j++;
    }
}
    TreeNode* balanceTree(vector<int> tree,int st,int en){
        
        if(st > en) return NULL;
        
        int mid = (st+en)/2;
        
        TreeNode* root =  TreeNode(tree[mid]);
        
        root->left = balanceTree(tree,st,mid-1);
        root->right = balanceTree(tree,mid+1,en);
        
        return root;
    }

Node* mergeTrees(Node* root1,Node* root2,int m,int n){
    vector<int> r1,r2,R;

    storeInorder(root1,r1);
    storeInorder(root2,r1);

    merge(r1,r2,R,m,n);

    return balancedTree(R,0,m + n - 1);

}

// kth largest element
int ans;

void kthLargestUtil(Node *root, int k, int &c) 
{ 

    if (root == NULL || c >= k) 
        return; 

    kthLargestUtil(root->right, k, c); 

    c++; 

    if (c == k) 
    { 
        ans = root->data; 
        return; 
    } 

    kthLargestUtil(root->left, k, c); 
}

int kthLargest(Node *root, int K)
{
    int c=0;
    kthLargestUtil(root,K,c);
    
    return ans;
}

// kth smallest element
Node* kthSmallest(Node* root, int& k)
{
    // base case
    if (root == NULL)
        return NULL;
 
    // search in left subtree
    Node* left = kthSmallest(root->left, k);
 
    // if k'th smallest is found in left subtree, return it
    if (left != NULL)
        return left;
 
    // if current element is k'th smallest, return it
    k--;
    if (k == 0)
        return root;
 
    // else search in right subtree
    return kthSmallest(root->right, k);
}

int KthSmallestElement(Node *root, int K)
{
    //add code here.
    Node *n = kthSmallest(root,K);
    if(n==NULL) return -1;
    return n->data;
}

// count of pairs with sum x
int countPairs(Node* root1, Node* root2, int x)
{
    if (root1 == NULL || root2 == NULL)
        return 0;
    int count =0;
    stack<Node*> st1, st2;
    Node* top1, *top2;
    
    while(1){
        while(root1!=NULL){
            st1.push(root1);
            root1=root1->left;
        }
        while(root2!=NULL){
            st2.push(root2);
            root2=root2->right;
        }
        
        if(st1.empty() || st2.empty())
            break;
            
        top1 = st1.top();
        top2 = st2.top();
        
        if((top1->data + top2->data) == x){
            count++;
            
            st1.pop();
            st2.pop();
            
            root1 = top1->right;
            root2 = top2->left;
        }
        else if((top1->data + top2->data) < x){
            st1.pop();
            
            root1 = top1->right;
        }
        else{
            st2.pop();
            root2 = top2->left;
        }
    }
    
    return count;
}

