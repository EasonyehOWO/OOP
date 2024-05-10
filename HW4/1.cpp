#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

struct treeNode{
    treeNode *left, *right;
    char val;
};typedef treeNode treeNode;
int arrow=0;

treeNode* rebuild(int l, int r, vector<char> pre, vector<char> in){
    treeNode *node=new treeNode;
    if(l>r){
        return nullptr;
    }
    node->val=pre[arrow];
    if(l==r){
        arrow++;
        node->left=node->right=nullptr;
        return node;
    }
    //cout<<node->val;
    re(i,l,r+1){
        if(in[i]==pre[arrow]){
            arrow++;
            node->left=rebuild(l, i-1, pre, in);
            node->right=rebuild(i+1, r, pre, in);
            break;
        }
    }
    return node;
}

void postorder(treeNode *node){
    if(node->left){
        postorder(node->left);
    }
    if(node->right){
        postorder(node->right);
    }
    cout<<node->val;
}

int main(){
    vector<char> pre, in;
    string s;
    cin>>s;
    re(i,0,s.size()){
        pre.push_back(s[i]);
    }
    cin>>s;
    re(i,0,s.size()){
        in.push_back(s[i]);
    }
    treeNode *root=rebuild(0, pre.size()-1, pre, in);
    if(root != NULL)postorder(root);
    cout<<'\n';
    return 0;
}
//ABCDE BADCE