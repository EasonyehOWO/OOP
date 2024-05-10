#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

class solution{
    public:
        using edge = struct{int D; pair<int,int> vertex;};
        int n, temp;
        vector<edge> v;
        solution(){
            cin>>n;
            v=makeEdges(n);
            int start, end;
            cin>>start>>end;
            pair<vector<int>, int> result=dijkstra(start-1, end-1);
            cout<<"Path =";
            for(auto i:result.first) cout<<" "<<i+1;
            cout<<"; "<<result.second<<" second delay\n";

        }

    private:
        vector<edge> makeEdges(int n){
            vector<edge> v;
            re(i,0,n){
                cin>>temp;
                re(owo, 0, temp){
                    edge e;
                    e.vertex.first=i;
                    cin>>e.vertex.second>>e.D;
                    e.vertex.second--;
                    v.push_back(e);
                }
            }
            return v;
        }

        pair<vector<int>, int> dijkstra(int start, int end){
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
};

int main(){
    solution sol;
    
    return 0;
}
/*
5
2 3 3 4 6
3 1 2 3 7 5 6
1 4 5
0
1 4 7
2 4     
*/