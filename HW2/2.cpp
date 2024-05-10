#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#define ll long long
#define re(i,m,n) for(int i=m;i<n;i++)

int main(){
    stack<int> table, storage;
    int n, a[1006], ctr=0;
    cin>>n;
    re(i,0,n){
        cin>>a[i];
        storage.push(n-i);
    } 
    while(!table.empty() || !storage.empty()){
        if(storage.empty() && !table.empty() && table.top()!=a[ctr]){
            cout<<"NO"<<endl;
            return 0;
        }
        if(!storage.empty() && storage.top()==a[ctr]){
            storage.pop();
            ctr++;
        }
        else if(!table.empty() && table.top()==a[ctr]){
            table.pop();
            ctr++;
        }
        else{
            table.push(storage.top());
            storage.pop();
        }
    }
    cout<<"YES"<<endl;
    return 0;
}