
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