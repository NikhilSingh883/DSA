
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

// nodes in the range

int getCount(Node *root, int l, int h)
{
    if(!root) return 0;
    
    if(root->data ==l && root->data == h) return 1;
    
    if(root->data >=l && root->data <= h)
        return 1 + getCount(root->left,l,h)
                 + getCount(root->right,l,h);
                 
    else if(root->data < l)
        return getCount(root->right,l,h);
    
    return getCount(root->left,l,h);
}

// conflicting nodes with the interval

ITNode* insert(ITNode *root,Interval i){
    if(root == NULL) return new ITNode(i);

    int l = root->i->low;

    if(i.low < l ){
        root->left = insert(root->left,i);
    }
    else root->right = insert(root->right,i);

    if(root->max < i.high)
        root->max = i.high;

    return root;
}

bool doOverlap(Interval i,Interval j){
    if(i.low < j.high && j.low < i.high)
        return true;
    return false;
}

Interval* overlapSearch(ITNode *root,Interval i){
    if(!root) return root;

    if(doOverlap(*(root->i),i))
        return root->i;

    if(!root->left && root->left->max >= i.low)
        return overlapSearch(root->left,i);

    return overlapSearch(root->right,i);
}

void printConflicting(Interval appt[],int n){
    ITNode* root = NULL;

    root = insert(root,appt[0]);

    for(int i=1;i<n;i++){
        Interval* res = overlapSearch(root,appt[i]);
        if(res){
            cout << res->low <<" "<<res->high<<endl;
        }

        root = insert(root,appt[i]);
    }
}

// preorder to postorder
Node* build(int min,int max,int &i,int pre[],int n){
    Node* root = NULL;
    
    if(pre[i] > min && pre[i]<max){
        root = newNode(pre[i]);
        i++;
        
        if(i<n)
            root->left = build(min,root->data,i,pre,n);
        if(i<n)
            root->right = build(root->data,max,i,pre,n);
    }
    
    return root;
}

void postOrder(Node* root){
    if(!root) return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data <<" ";
}

Node* constructTree(int pre[], int size) {
    //code here
    int i=0;
    Node* root = build(INT_MIN,INT_MAX,i,pre,size);
    // postOrder(root);
    return root;
}

// Check whether BST contains Dead End

void storeNodes(Node * root, unordered_set<int> &all_nodes,
                          unordered_set<int> &leaf_nodes)
{
    if (root == NULL)
        return ;
 
    all_nodes.insert(root->data);
 
    if (root->left==NULL && root->right==NULL)
    {
        leaf_nodes.insert(root->data);
        return ;
    }
 
    storeNodes(root-> left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}
 
bool isDeadEnd(Node *root)
{
    if (root == NULL)
        return false ;
 
    unordered_set<int> all_nodes, leaf_nodes;
 
    all_nodes.insert(0);
 
    storeNodes(root, all_nodes, leaf_nodes);
 
    for (auto i = leaf_nodes.begin() ; i != leaf_nodes.end(); i++)
    {
        int x = (*i);
 
        if (all_nodes.find(x+1) != all_nodes.end() &&
            all_nodes.find(x-1) != all_nodes.end())
            return true;
    }
 
    return false ;
}

// flatten BST

void inorder(Node*root ,Node* prev){
    if(!root) return;

    inorder(root->left,prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    inorder(root->right,prev)
}

Node* flatten(Node* root){

    Node* prev = newNode(-1);

    inorder(root,prev);

    prev->left = NULL;
    Node* ret = prev->right;

    delete prev;
    return ret;
}

// largest bst in bt
int h;

bool func(Node* root, int *mx, int* mn, int *num)
{
    if(root == NULL)
    return true;
    
    int m1 = INT_MIN,m2 = INT_MAX, x1 = 0;
    int m3 = INT_MIN, m4 = INT_MAX, x2 = 0;
    bool a = func(root->left, &m1, &m2, &x1);
    bool b = func(root->right, &m3, &m4, &x2);
    
    *mx = max(root->data, max(m1, m3));
    *mn = min(root->data, min(m2, m4));
    
 
    
    if(a == true && b == true && root->data < m4 && root->data > m1)
    {
        *num = x1+x2+1;
        h = max(*num, h);
        return true;
    }
    
    return false;
    
    
    
}

int largestBst(Node *root)
{
    h = INT_MIN;
    int a = INT_MIN,b = INT_MAX, c = 0;
    func(root, &a, &b, &c);
    if(h == INT_MIN)
    return 0;
    
    return h;
    
}

// replace with least largest to its right

void insert(Node*& node, int data, Node*& succ)
{
    if (node == NULL)
        node = newNode(data);

    if (data < node->data)
    {
        succ = node;
        insert(node->left, data, succ);
    }
 
    else if (data > node->data)
        insert(node->right, data, succ);
}

void replace(int arr[], int n)
{
    Node* root = NULL;

    for (int i = n - 1; i >= 0; i--)
    {
        Node* succ = NULL;

        insert(root, arr[i], succ);

        if (succ)
            arr[i] = succ->data;
        else    
            arr[i] = -1;
    }
}

// 

