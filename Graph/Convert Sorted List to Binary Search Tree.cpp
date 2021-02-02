TreeNode* bst(int i,int l,vector<int> &arr){
    if(i>l)
        return NULL;
    int mid = (l+i)/2;
    TreeNode* node = new TreeNode(arr[mid]);
    node->left = bst(i,mid-1,arr);
    node->right = bst(mid+1,l,arr);
    return node;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    vector<int> arr;
    while(A!=NULL){
        arr.push_back(A->val);   
        A = A->next;
    }
    return bst(0,arr.size()-1,arr);
}