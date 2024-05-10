#include<bits/stdc++.h>
using namespace std;
using edge = struct{int D; pair<int,int> vertex;};
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

map<pair<int, int>, int> v2v;
pair<vector<int>, int> dijkstra(int start, int end, vector<edge> v, int n);

int main(){
    int n, sNum, temp, a, b, d,ans=INT_MAX, ansv;
    vector<int> dist2s;
    vector<edge> v;
    vector<int> sPos;
    cin>>sNum>>n;
    re(i,0,sNum){
        cin>>temp;
        sPos.push_back(temp-1);
    } 
    while(cin>>a>>b>>d){
        edge e;
        e.vertex.first=a-1;
        e.vertex.second=b-1;
        e.D=d;
        v.push_back(e);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pair<vector<int>, int> result=dijkstra(i, j, v, n);
            v2v[{i,j}]=result.second;
        }
    }
    for(int i=0;i<n;i++){
        vector<int>:: iterator iter = find(sPos.begin(), sPos.end(), i);
        if(iter!=sPos.end()){
            dist2s.push_back(0);
        }
        else{
            temp=INT_MAX;
            for(auto s:sPos){
                a=min(s, i);
                b=max(s, i);
                if(v2v.find({a,b})!=v2v.end()){
                    temp=min(temp, v2v[{a,b}]);
                }
                else printf("Error\n");
            }
            dist2s.push_back(temp);
        }
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            //cout<<dist2s[j]<<' '<<v2v[{min(i,j),max(i,j)}]<<endl;
            temp=dist2s[j]<v2v[{min(i,j),max(i,j)}] ? dist2s[j] : v2v[{min(i,j),max(i,j)}];
            sum=sum<temp ? temp : sum;
        }

        if(sum<ans){
            ans=sum;
            ansv=i;
        }
    }
    cout<<ansv+1<<endl;
    return 114514;
}

pair<vector<int>, int> dijkstra(int start, int end, vector<edge> v, int n){
    using pp = pair<int,int>;
    vector<int> dist(n, INT_MAX);
    priority_queue<pp, vector<pp>, greater<pp>> pq;//first is distance, second is vertex
    vector<bool> visited(n, false);
    vector<int> prev(n, -1);
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(visited[u])continue;
        visited[u]=true;
        for(auto i:v){
            if(i.vertex.first==u){
                if(dist[i.vertex.second]>dist[u]+i.D){
                    dist[i.vertex.second]=dist[u]+i.D;
                    prev[i.vertex.second]=u;
                    pq.push({dist[i.vertex.second], i.vertex.second});
                }
            }
            if(i.vertex.second==u){
                if(dist[i.vertex.first]>dist[u]+i.D){
                    dist[i.vertex.first]=dist[u]+i.D;
                    prev[i.vertex.first]=u;
                    pq.push({dist[i.vertex.first], i.vertex.first});
                }
            }
        }
    }
    vector<int> path;
    int delay=dist[end];
    while(end!=-1){
        path.push_back(end);
        end=prev[end];
    }
    reverse(path.begin(), path.end());
    return {path, delay};
}

/*
2 7 
1 7
1 2 10
2 3 10
3 4 10
4 5 10
5 6 10
6 7 10
7 1 10

1 4
1
1 2 1
2 3 1
3 4 1
1 4 1
2 4 1
1 3 10

2 8
1 4
1 5 10
2 4 10
7 6 10
3 8 10
1 2 10
3 7 10
4 8 10
*/
