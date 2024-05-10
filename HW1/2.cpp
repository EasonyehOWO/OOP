#include<bits/stdc++.h>
using namespace std;

int main(){
    int t=0,testcases;
    int a[305][305];
    cin>>testcases;
    while(++t<=testcases){
        bool sym=true;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
    
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i][j]!=a[j][i]){
                    sym=false;
                }
            }
        }
        if(sym)printf("Test #%d: Symmetric.\n",t);
        else printf("Test #%d: Non-symmetric.\n",t);
    }
    return 0;
}