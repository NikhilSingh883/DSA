
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

