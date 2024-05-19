#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

int main(){
    int n, a[1000], ctr=0;
    cin>>n;
    re(i,0,n)cin>>a[i];
    for(int i=n;i>0;i--){
        for(int j=0;j<i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
                ctr++;
            }
        }
    }
    cout<<ctr<<endl;
    return 0;
}