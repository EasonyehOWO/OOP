#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long
/*
e9 3a e9 c5 fc 73 55 d5
XOR
f4 3a fe c7 e1 68 4a df
*/

vector<int> target = {0x1d, 0x00, 0x17, 0x02, 0x1d, 0x1b, 0x1f, 0x0a};

vector<int> CharXor(string a, string b){
    vector<int> v;
    v.clear();
    for(int i=0;i<a.size();i++){
        v.push_back(a[i]^b[i]);
    }
    return v;
}

bool Break_Complete(string a, string b){
    vector<int> v = CharXor(a, b);
    if(v == target){
        return true;
    }
    return false;
}


int main(){
    string s;
    int cato;
    vector<string> v[26];
    while(cin>>s){
        cato = s[1]-'a';
        v[cato].push_back(s);
    }
    re(i,0,26){
        for(int j=0;j<v[i].size();j++){
            for(int k=0;k<j;k++){
                if(Break_Complete(v[i][k], v[i][j])){
                    cout<<v[i][k]<<" "<<v[i][j]<<endl;
                }
            }
        }

    }


    return 0;
}

//owner: 112550095