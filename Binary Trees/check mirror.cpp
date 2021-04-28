int areMirror(TreeNode* a, TreeNode* b)
{
    /* Base case : Both empty */
    if (a==NULL && b==NULL)
        return true;
  
    // If only one is empty
    if (a==NULL || b == NULL)
        return false;
  
    /* Both non-empty, compare them recursively
     Note that in recursive calls, we pass left
     of one tree and right of other tree */
    return  a->data == b->data &&
            areMirror(a->left, b->right) &&
            areMirror(a->right, b->left);
}