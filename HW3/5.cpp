#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

int a[100020],sa[100020];

int findmax(int n){
    int maxa=-9999999;
    sa[0]=a[0];
    re(i,1,n){
        sa[i]=sa[i-1]+a[i]>0 ? sa[i-1]+a[i] : 0;
        maxa=sa[i]>maxa ? sa[i] : maxa;
    }
    return maxa>a[0] ? maxa : a[0];

}

int findmin(int n){
    int mina=9999999;
    sa[0]=a[0];
    re(i,1,n){
        sa[i]=sa[i-1]+a[i]<0 ? sa[i-1]+a[i] : 0;
        mina=sa[i]<mina ? sa[i] : mina;
    }
    return mina<a[0] ? mina : a[0];

}

int main(){
    int n;
    cin>>n;
    re(i,0,n) cin>>a[i];
    int sum=0;
    int maxa=-9999999;
    re(i,0,n){
        sum+=a[i];
        maxa=a[i]>maxa ? a[i] : maxa;
    }
    int ans=max(findmax(n), sum-findmin(n));
    if(ans==0){
        ans=maxa;
    }
    cout<<max(maxa, ans)<<'\n';
    
    return 0;
}

//1 2 -3 4 -3 -2 -3 -1
//1 -2 -3 4 -3 2 -3 -1
