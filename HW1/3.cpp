#include<bits/stdc++.h>
using namespace std;
//#define DEBUG

int sum[30][30];
int temp[30];

int hearvesting(int upperlim, int lowerlim,int n){
    int ret=0;
    for(int i=0;i<n;i++){
        temp[i]=sum[lowerlim][i]-sum[upperlim][i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            int tsum=0;
            for(int k=j;k<=i;k++){
                tsum+=temp[k];
            }
            ret=max(ret,tsum);
        }
    }
    if(upperlim==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int tsum=0;
                for(int k=j;k<=i;k++){
                    tsum+=sum[lowerlim][k];
                }
                ret=max(ret,tsum);
            }
        }
    }
    return ret;
}

int main(){
    int n,ans=0;
    cin>>n;
    int a[30][30];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        sum[0][i]=a[0][i];
        for(int j=1;j<n;j++){
            sum[j][i]=sum[j-1][i]+a[j][i];
        }
    }
    #ifdef DEBUG
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sum[i][j]<<' ';
        }
        cout<<endl;
    }
    #endif
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            ans=max(ans,hearvesting(j,i,n));
        }
    }
    cout<<ans<<endl;
    return 0;
}