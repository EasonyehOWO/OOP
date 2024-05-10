#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

void checkAdj(vector<pair<int, int>> edges, bool *checked, int n, int start){
    checked[start]=true;
    for(int i=0;i<n;i++){
        if(edges[i].first==start){
            if(checked[edges[i].second]==false){
                checked[edges[i].second]=true;
                checkAdj(edges, checked, n, edges[i].second);
            }
        }
        else if(edges[i].second==start){
            if(checked[edges[i].first]==false){
                checked[edges[i].first]=true;
                checkAdj(edges, checked, n, edges[i].first);
            }
        }
    }
}

int main(){
    char c;
    cin>>c;
    int n=c-'A'+1;
    int sum=0, edgeNum;
    vector<pair<int, int>> edges;
    string inp;
    while(cin>>inp && inp[0]!='\n'){
        if(inp=="0") break;
        edges.push_back({inp[0]-'A', inp[1]-'A'});
    }
    edgeNum=edges.size();
    bool checked[40];
    for(int i=0;i<n;i++){
        checked[i]=false;
    }  
    for(int i=0;i<n;i++){
        if(checked[i]==false){
            checkAdj(edges, checked, edgeNum, i);
            sum++;
        }
    }
    cout<<sum<<endl;
    
}
/*
E
AB
CE
DB
EC

G
AB
CE
DB
EC
EF
GG
*/