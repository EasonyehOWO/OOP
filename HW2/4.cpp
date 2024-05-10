#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#define ll long long
#define re(i,m,n) for(int i=m;i<n;i++)

bool compare(vector<char> a, vector<char> b){
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            if(a[i]<b[i])
                return true;
            else
                return false;
        }
    }
    return false;
}

int main(){
    vector<char> origin, ans, temp;
    int n,k=1;
    cin>>n;
    re(i,0,n){
        char tempC;
        cin>>tempC;
        origin.push_back(tempC);
    }
    ans = origin;
    for(int i=0;i<n;i++){
        temp = origin;
        int arrow=0;
        while(n-arrow>i){
            //swap(temp[arrow],temp[arrow+i]);
            for(int j=0;j<(i+1)/2;j++){
                swap(temp[arrow+j],temp[arrow+i-j]);
            }
            arrow++;
        }
        if(compare(temp,ans)){
            //cout<<i<<endl;
            ans = temp;
            k=i+1;
        }
    }
    
    for(int i=0;i<n;i++)
        cout<<ans[i];
    cout<<endl<<k<<endl;
    return 0;
}