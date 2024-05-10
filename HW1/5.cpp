#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string inp;
    vector<string> words;
    for(int i=0;i<n;i++){
        cin>>inp;
        words.push_back(inp);
    }

    unordered_set<string> wordSet(words.begin(), words.end());
    int count=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string wordA = words[i];
            string wordB = words[j];
            if(wordA[0]==wordB[0])continue;
            swap(wordA[0], wordB[0]);

            if(wordSet.find(wordA)==wordSet.end() && wordSet.find(wordB)==wordSet.end()){
                ++count;
            }
        }
    }

    cout<<count*2<<endl;
    return 0;
}

//6 abb add cbb cdd cff czz
//4 aa bb ab ba
//4 aaa bbb abb baa
//2 rr ar
//2 aa bb
//7 ax bx cx az bz cz aw //16-2-1-1-3-2-1-1-3
//4 ax bx ag bh

//7 ax bx cx a12 a34 b56 c78