#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

vector<int> finding(vector<pair<int,int>> v, int a){
    vector<int> ret;
    for(auto i:v){
        if(i.first==a){
            ret.push_back(i.second);
            vector<int> tmp=finding(v,i.second);
            for(auto j:tmp){
                ret.push_back(j);
            }
        }
    }
    return ret;
}

int main(){
    int a,b,f,root;
    vector<int> va,vb;
    vector<pair<int,int>> p;

    while(cin>>a>>b && a!=0 && b!=0){
        p.push_back({a,b});
        f=1;
        re(i,0,vb.size()){
            if(vb[i]==b){
                cout<<"False\n";
                return 0;
            }
        }
        for(auto i:va){
            if(i==a)f=0;
        }
        if(f)va.push_back(a);
        f=1;
        for(auto i:va){
            if(i==b)f=0;
        }
        if(f)va.push_back(b);
        vb.push_back(b);
        
    }

    if(va.size()==0){
        cout<<"True\n";
        return 0;
    }

    if(va.size()!=vb.size()+1){
        cout<<"False\n";
        return 0;
    }
    f=1;
    for(int i=0;i<va.size() && f;i++){
        for(auto j:vb){
            if(va[i]==j)break;
            if(j==vb[vb.size()-1]){
                root=va[i];
                f=0;
                break;
            }
        }
    }

    vector<int> singcheck=finding(p,root);
    if(singcheck.size()!=va.size()-1){
        cout<<"False\n";
        return 0;
    }
    cout<<"True\n";
    return 0;
}