#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#define ll long long
#define re(i,m,n) for(int i=m;i<n;i++)

int grouped[1000006];

int main(){
    
    int testCaseQuantity,n,memberQuantity,moves,temp;
    string command;
    vector<int> member;
    vector<vector<int>> teams;
    pair<int,int> individual;//team, NO.
    vector<queue<pair<int,int>>> line;
    cin>>testCaseQuantity;
    for(int testTimes=0;testTimes<testCaseQuantity;testTimes++){
        re(i,0,1000006)
            grouped[i]=0;
        cout<<"Testcase #"<<testTimes+1<<"\n";
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>memberQuantity;
            while(memberQuantity--){
                cin>>temp;
                member.push_back(temp);
                grouped[temp]=i+1;
            }
            teams.push_back(member);
            member.clear();
        }
        cin>>moves;
        //cout<<"AAA"<<endl;
        for(int i=0;i<moves;i++){
            cin>>command;
            if(command == "ENQUEUE" || command == "E"){
                cin>>temp;
                if(grouped[temp]==0){
                    individual.first=0;
                    individual.second=temp;
                    queue<pair<int,int>> tempQueue;
                    tempQueue.push(individual);
                    line.push_back(tempQueue);
                    tempQueue.pop();
                }
                else{
                    individual.first=grouped[temp];
                    individual.second=temp;
                    for(int j=0;j<line.size();j++){
                        if(!line[j].empty() && line[j].front().first==individual.first){
                            line[j].push(individual);
                            individual.first=-1;
                            break;
                        }
                    }
                }  
                if(individual.first!=-1 && individual.first!=0){
                    queue<pair<int,int>> tempQueue;
                    tempQueue.push(individual);
                    line.push_back(tempQueue);
                    tempQueue.pop();
                }
                
            }
            if(command == "DEQUEUE" || command == "D"){
                for(int j=0;j<line.size();j++){
                    if(!line[j].empty()){
                        cout<<line[j].front().second<<endl;
                        line[j].pop();
                        break;
                    }
                }
            }
            if(command == "CH"){
                for(int j=0;j<line.size();j++){
                    while(!line[j].empty()){
                        cout<<line[j].front().first<<' ';
                        cout<<line[j].front().second<<endl;
                        line[j].pop();
                    }
                }
            }
        }

        while(!teams.empty()){
            int t=teams.size() - 1;
            for(int i=0;i<teams[t].size();i++){
                grouped[teams[t][i]]=0;
            }
            teams.pop_back();
        }
        line.clear();
        member.clear();
        individual.first=0;
        individual.second=0;
        teams.clear();
    }
    return 0;
}
/*
2
2
2 1 2
2 3 4
12
E 1
E 5
E 3
E 6
E 2
E 4
D
D
D
D
D
D
2
2 1 2
2 5 6
12
E 1
E 5
E 3
E 6
E 2
E 4
D
D
D
D
D
D
*/