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