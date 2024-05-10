#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#define ll long long
#define re(i,m,n) for(int i=m;i<n;i++)

int main(){
    ll n,cnt=0;
    cin>>n;
    ll a[n];
    re(i,0,n) cin>>a[i];

    for(int i=0;i<n-1;i++){
        if(a[i+1]<a[i]){
            cnt++;
            if(i==0)continue;
            if(a[i-1]<a[i])
                a[i]=a[i-1];
            else
                a[i+1]=a[i];
        }
    }
    if(cnt>1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}