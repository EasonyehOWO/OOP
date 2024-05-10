#include<bits/stdc++.h>
using namespace std;
#define DEBUG

int a[25][25];
int main(){
    int n;
    cin>>n;
    int nx=0,ny=0,num=1,status=0;
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++){
            a[i][j]=0;
        }
    }
    while(num<=n*n){
        if(status==0){
            if(nx<n && ny<n && nx>=0 && ny>=0 && a[nx][ny]==0){
                a[nx][ny]=num;
                num++;
                ny++;
            }
            else{
                ny--;
                nx++;
                status=1;
            }
        }
        else if(status==1){
            if(nx<n && ny<n && nx>=0 && ny>=0 && a[nx][ny]==0){
                a[nx][ny]=num;
                num++;
                nx++;
            }
            else{
                nx--;
                ny--;
                status=2;
            }
        }
        else if(status==2){
            if(nx<n && ny<n && nx>=0 && ny>=0 && a[nx][ny]==0){
                a[nx][ny]=num;
                num++;
                ny--;
            }
            else{
                ny++;
                nx--;
                status=3;
            }
        }
        else if(status==3){
            if(nx<n && ny<n && nx>=0 && ny>=0 && a[nx][ny]==0){
                a[nx][ny]=num;
                num++;
                nx--;
            }
            else{
                nx++;
                ny++;
                status=0;
            }
        }
    }
    cout<<'[';
    for(int i=0;i<n;i++){
        if(i)cout<<',';
        cout<<'[';
        for(int j=0;j<n;j++){
            if(j)cout<<',';
            cout<<a[i][j];
        }
        cout<<']';
    }
    cout<<']';
    cout<<endl;
    return 0;
}