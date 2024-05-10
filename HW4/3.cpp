#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

struct treeNode{
    treeNode *left, *right;
    int val;
};typedef treeNode treeNode;

treeNode* buildTree(int l, int r, vector<int> pre){
    treeNode *node=new treeNode;
    node->val=pre[l];
    if(l>r){
        return nullptr;
    }
    if(l==r){
        node->left=node->right=nullptr;
        return node;
    }
    for(int i=l+1;i<=r;i++){
        if(pre[i]>pre[l]){
            node->left=buildTree(l+1, i-1, pre);
            node->right=buildTree(i, r, pre);
            break;
        }
        else if(i==r){
            node->left=buildTree(l+1, r, pre);
            node->right=nullptr;
        }
    }
    return node;
}

void postorder(treeNode *node, int command=0){
    if(node->left){
        postorder(node->left, 1);
    }
    if(node->right){
        postorder(node->right, 1);
    }
    cout<<node->val;
    if(command==0)cout<<'\n';
    else cout<<' ';
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    re(i,0,n){
        cin>>v[i];
    }
    treeNode *root=buildTree(0, n-1, v);
    postorder(root);

    return 0;
}