#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

using pos = struct{int x,y,z;};

vector<vector<vector<bool>>> d;
pos mov[6]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};

int DFSdungeon(pos np, pos exit){
    if(np.x==exit.x && np.y==exit.y && np.z==exit.z) return 0;
    d[np.x][np.y][np.z]=false;
    int ans=-1;
    for(int i=0;i<6;i++){
        pos nnp={np.x+mov[i].x, np.y+mov[i].y, np.z+mov[i].z};
        if(nnp.x<0 || nnp.x>=d.size() || nnp.y<0 || nnp.y>=d[0].size() || nnp.z<0 || nnp.z>=d[0][0].size()) continue;
        if(d[nnp.x][nnp.y][nnp.z]){
            int temp=DFSdungeon(nnp, exit);
            if(temp!=-1){
                if(ans==-1) ans=temp+1;
                else ans=min(ans, temp+1);
            }
        }
    }
    d[np.x][np.y][np.z]=true;
    return ans;
}

int main(){
    int l,r,c;
    cin>>l>>r>>c;
    pos np,exit;
    for(int i=0;i<l;i++){
        vector<vector<bool>> temp;
        for(int j=0;j<r;j++){
            vector<bool> temp2;
            for(int k=0;k<c;k++){
                char c;
                cin>>c;
                if(c!='S' && c!='E' && c!='#' && c!='.'){k-=1;continue;}
                if(c=='S') np={i,j,k};
                if(c=='E') exit={i,j,k};
                if(c=='#') temp2.push_back(false);
                else temp2.push_back(true);
            }
            temp.push_back(temp2);
        }
        d.push_back(temp);
    }
    int ans=DFSdungeon(np, exit);
    if(ans==-1) cout<<"Trapped!"<<endl;
    else cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
}
/*
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E
*/