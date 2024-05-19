#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

ll hasher(ll c, ll w, int n){
    return (c/w)%n;
}

ll sol(vector<ll> v, int n){
    int f[20];
    bool end=0;
    ll C=1;
    while(!end){
        end=1;
        memset(f, -1, sizeof(f));
        re(i, 0, n){
            ll h = hasher(C, v[i], n);
            if(f[h]!=-1){
                C= min((C/v[i]+1)*v[i], (C/v[f[h]]+1)*v[f[h]]);
                end=0;
                break;
            }
            f[h]=i;
        }
    }
    return C;
}

int main(){
    int n, ctr=0;
    ll sum=0, C;
    vector<ll> v;
    cin>>n;
    getchar();
    for(int owob=0;owob<n;owob++){
        char c;
        string s;
        vector<string> ss;
        sum=0;
        while(1){
            cin>>s;
            sum=0;
            for(int i=0;i<s.size();i++){
                if(s[i]>='a'&&s[i]<='z'){
                    sum*=32;
                    sum+=s[i]-'a'+1;
                }
            }
            v.push_back(sum);
            ss.push_back(s);
            c=getchar();
            if(c!=' ') break;
        }/*
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                sum*=32;
                sum+=s[i]-'a'+1;
            }
                
            else if(s[i]==' '){
                ctr++;
                v.push_back(sum);
                sum=0;
            }
        }*/
        C = sol(v, v.size());
        for(int i=0;i<ss.size();i++){
            if(i!=0) cout<<' ';
            cout<<ss[i];
        }
        cout<<'\n'<<C<<"\n\n";
        v.clear();
    }
    
    return 0;
}