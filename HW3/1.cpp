#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

int main(){
    int a[20000];
    int n;
    int temp;
    cin>>n;
    re(i,0,n) cin>>a[i];
    re(i,0,n-1){
        temp=i+1;
        while (temp!=n && a[i]>=a[temp])
        {
            temp++;
        }
        if(i!=0)cout<<" ";
        if(temp!=n)cout<<temp-i;
        else cout<<"0";
    }
    cout<<' '<<0<<'\n';
    return 0;
}