#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#define ll long long
#define re(i,m,n) for(int i=m;i<n;i++)

int main(){
    int n,temp;
    cin>>n;
    ll a[50050];
    ll ans=0; 
    re(i,0,n) cin>>a[i];
    pair<int,int> lim[50050];
    for(int i=0;i<n;i++){
        lim[i].first=i;
        lim[i].second=i;
    }

    for(int i=0;i<n;i++){
        temp=i;
        while(temp>0 && a[temp-1]<=a[i])
            temp=lim[temp-1].first;
        lim[i].first=temp;
        temp=i;
        while(temp<n-1 && a[temp+1]<=a[i])
            temp=lim[temp+1].second;
        lim[i].second=temp;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<=min(n-1,lim[i].second+1);j++){
            if(lim[j].first<=i+1){
                ans++;
                //cout<<i<<' '<<j<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}