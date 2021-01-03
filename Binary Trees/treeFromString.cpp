#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right ;
    Node* left ;
};

Node* newNode(int data){
    Node* node = new Node();
    
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

void preOrder(Node *root){
    
    unordered_map<Node*,int> mp;
    
    if(root == NULL) return;
    
    stack<Node*> s;
    
    s.push(root);
    
    while(!s.empty()){
        Node* curr = s.top();
        
        if(curr == NULL){
            s.pop();
            continue;
        }
        
        if(mp[curr]==0) cout << curr ->val <<" ";
        else if(mp[curr] == 1) s.push(curr->left);
        else if(mp[curr]== 2) s.push(curr->right);
        else s.pop();
        
        mp[curr]++;
    }
}

int findIndex(string str, int si, int ei)
{
    if (si > ei)
        return -1;

    stack<char> s;
 
    for (int i = si; i <= ei; i++) {
        if (str[i] == '(')
            s.push(str[i]);

        else if (str[i] == ')') {
            if (s.top() == '(') {
                s.pop();
                if (s.empty())
                    return i;
            }
        }
    }
    return -1;
}

Node* treeFromString(string str,int si,int ei){
    if(si>ei) return NULL;
    
    
    Node* root = newNode(str[si]-'0');
    int idx = -1;
    
    if(si +1 <= ei && str[si+1]=='(')
        idx = findIndex(str,si+1,ei);
        
    if(idx!=-1){
        root -> left = treeFromString(str,si+2,idx-1);
        root -> right = treeFromString(str,idx+2,ei-1);
    }
    return root;
}

int main()
{
    string str = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(str, 0, str.length() - 1);
    preOrder(root);
}