#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long
int a[305][305];
int n,m;

void islandProcess(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m || a[x][y]==0){
        return;
    }
    if(a[x][y]==2){
        islandProcess(x+1,y);
        islandProcess(x-1,y);
        islandProcess(x,y+1);
        islandProcess(x,y-1);
    }
    if(a[x][y]==1){
        a[x][y]=0;
        islandProcess(x+1,y);
        islandProcess(x-1,y);
        islandProcess(x,y+1);
        islandProcess(x,y-1);
    }

}


void islandScanner(){
    re(i,0,n){
        re(j,0,m){
            if(a[i][j]==1){
                a[i][j]=2;
                islandProcess(i,j);
            }
        }
    }

}
int main(){
    cin>>n>>m;
    re(i,0,n){
        re(j,0,m){
            cin>>a[i][j];
        }
    }
    int ctr=0;
    islandScanner();
    re(i,0,n){
        re(j,0,m){
            if(a[i][j]==2){
                ctr++;
            }
        }
    }
    cout<<ctr<<'\n';


    return 0;
}