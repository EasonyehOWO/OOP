#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

struct treeNode
{
    int apple;
    vector<int> children;
};

unordered_map<int,treeNode> tree;

pair<pair<int, int>, int> allocate(int code){//child apple move
    int appleSum=tree[code].apple, child=1, move=0;
    if(tree[code].children.size()==0){
        return {{child, appleSum}, abs(1-tree[code].apple)};
    }
    
    for(auto c:tree[code].children){
        pair<pair<int, int>, int> temp=allocate(c);
        appleSum+=temp.first.second;
        child+=temp.first.first;
        move+=temp.second;
    }
    return {{child, appleSum}, move+abs(child-appleSum)};
}

int main(){
    int n, code, appleNum, childNum, child;
    vector<int> va, vb;
    cin>>n;
    re(i,0,n){
        cin>>code>>appleNum>>childNum;
        tree[code].apple = appleNum;
        va.push_back(code);
        re(j,0,childNum){
            cin>>child;
            vb.push_back(child);
            tree[code].children.push_back(child);
        }
    }
    for(int i=0;i<va.size();i++){
        if(find(vb.begin(),vb.end(),va[i])==vb.end()){
            cout<<allocate(va[i]).second<<endl;
            break;
        }
    }
    return 0;
}