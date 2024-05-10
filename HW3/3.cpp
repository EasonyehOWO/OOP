#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

char s[5000];

int skipper(int arrow){
    int n=strlen(s);
    int ctr=1;
    while(ctr!=0){
        if(s[arrow]=='['){
            ctr++;
        }
        else if(s[arrow]==']'){
            ctr--;
        }
        arrow++;
    }
    return arrow-1;
}

int numcheck(int arrow){
    int n=strlen(s);
    int ans=0, times=1;
    while(arrow!=-1 && s[arrow]>='0' && s[arrow]<='9'){
        ans+=times*(s[arrow]-'0');
        times*=10;
        arrow--;
    }
    return ans;
}

vector<char> stringSolve(int arrow, int r){
    vector<char> ans;
    int n=strlen(s);
    while(arrow<n){
        if(s[arrow]=='['){
            //cout<<arrow<<' '<<r<<' ';
            vector<char> temp=stringSolve(arrow+1, numcheck(arrow-1));
            for(auto i:temp){
                ans.push_back(i);
            }
            arrow=skipper(arrow+1);
            
        }
        else if(s[arrow]==']'){
            int repsize = ans.size();
            re(repT, 1, r){
                for(int i=0;i<repsize;i++){
                    ans.push_back(ans[i]);
                }
            }
            return ans;
        }
        else if (s[arrow]>='a' && s[arrow]<='z'){
            ans.push_back(s[arrow]);
        }
        
        arrow++;
        
    }
    //cout<<arrow<<' '<<r<<'\n';
    
    return ans;

}

int main(){
    cin>>s;
    int n=strlen(s);
    int arrow=0;
    vector<char>ans = stringSolve(arrow, 1);
    for(auto i:ans){
        cout<<i;
    }
    cout<<'\n';

    return 0;
}