#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

int main(){
    string inp;
    stack<char> s;
    cin>>inp;
    re(i,0,inp.size()){
        if(s.empty()){
            s.push(inp[i]);
        }else{
            if(s.top()=='(' && inp[i]==')'){
                s.pop();
            }else{
                s.push(inp[i]);
            }
        }
    }
    cout<<s.size()<<endl;

    return 0;
}