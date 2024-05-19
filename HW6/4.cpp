#include<bits/stdc++.h>
using namespace std;
#define re(i,m,n) for(int i=m;i<n;i++)
#define ll long long

vector<int> mergesort(vector<int> v){
    if(v.size()==1) return v;
    vector<int> l, r;
    re(i,0,v.size()/2) l.push_back(v[i]);
    re(i,v.size()/2,v.size()) r.push_back(v[i]);
    l = mergesort(l);
    r = mergesort(r);
    vector<int> res;
    int i=0, j=0;
    while(i<l.size()&&j<r.size()){
        if(l[i]<r[j]){
            res.push_back(l[i]);
            i++;
        }
        else{
            res.push_back(r[j]);
            j++;
        }
    }
    while(i<l.size()){
        res.push_back(l[i]);
        i++;
    }
    while(j<r.size()){
        res.push_back(r[j]);
        j++;
    }
    return res;
}

int main(){
    int n, temp;
    cin>>n;
    vector<int> v(n);
    re(i,0,n){
        cin>>temp;
        v[i]=temp-i;
    }
    v=mergesort(v);
    int ctr=0, sum=0;
    for(int i=0;i<n-1;i++){
        if(v[i]==v[i+1]){
            ctr++;
        }
        else if(ctr>0){
            sum+=((ctr+1)*(ctr))/2;
            ctr=0;
        }
    }
    if(ctr>0){
        sum+=((ctr+1)*(ctr))/2;
        ctr=0;
    }
    cout<<sum<<endl;
    
    return 0;
}