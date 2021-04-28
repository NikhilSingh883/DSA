void mirror(struct Node* node) 
{
    if (node == NULL) 
        return; 
    else
    {
        struct Node* temp;
          
        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);
      
        /* swap the pointers in this node */
        temp     = node->left;
        node->left = node->right;
        node->right = temp;
    }
}