#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

class solution{
    public:
        int n;
        int a[200];
        solution(){
            cin>>n;
            re(i,0,n) cin>>a[i];
            sort(a,a+n);
            pairOfLottery(n);
        }
        
    private:
        void pairOfLottery(int n){
            for(int i=0;i<n-5;i++){
                for(int j=i+1;j<n-4;j++){
                    for(int k=j+1;k<n-3;k++){
                        for(int l=k+1;l<n-2;l++){
                            for(int m=l+1;m<n-1;m++){
                                for(int o=m+1;o<n;o++){
                                    cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<" "<<a[m]<<" "<<a[o]<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }
};

int main(){
    solution sol;
    
    return 0;
}