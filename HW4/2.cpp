#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

using ee = pair<int, pair<int, int>>;
pair<int, int> point[2000];
int edge[2000];
priority_queue<ee, vector<ee>, greater<ee>> pq;

int MST(int n, int p){
    int shortest=-1;
    edge[p]=0;
        for(int i=0;i<n;i++){
        if(edge[i]==0)continue;
        if(shortest==-1)shortest=i;
        int tmp=abs(point[p].first-point[i].first)+abs(point[p].second-point[i].second);
        edge[i] = tmp<edge[i] ? tmp : edge[i];
        shortest = edge[shortest]<edge[i] ? shortest : i;
    }
    int ret=edge[shortest];
    if(ret==0)return 0;
    return ret+MST(n, shortest);
}

int main(){
    int n;
    cin>>n;
    re(i,0,n){
        int x, y;
        cin>>x>>y;
        point[i]={x, y};
        edge[i]=100000000;
    }
    re(i,0,n){
        re(j,i+1,n){
            int x1=point[i].first, y1=point[i].second;
            int x2=point[j].first, y2=point[j].second;
            int dist=abs(x1-x2)+abs(y1-y2);
            pq.push({dist, {i, j}});
        }
    }
    cout<<MST(n,0)<<'\n';
    return 0;
}