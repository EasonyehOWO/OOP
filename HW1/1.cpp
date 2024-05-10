#include<iostream>  
#include<vector>  
#include<map>  
using namespace std;  
  
map<char, char> mirrorList = {  
    {'A','A'},  
    {'E','3'},  
    {'H','H'},  
    {'I','I'},  
    {'J','L'},  
    {'L','J'},  
    {'M','M'},  
    {'O','O'},  
    {'S','2'},  
    {'T','T'},  
    {'U','U'},  
    {'V','V'},  
    {'W','W'},  
    {'X','X'},  
    {'Y','Y'},  
    {'Z','5'},  
    {'1','1'},  
    {'2','S'},  
    {'3','E'},  
    {'5','Z'},  
    {'8','8'},  
    {'0','0'},  
    {'0','O'},  
    {'O','0'}  
};  
      
bool checkmir(char a, char b){  
    map<char, char>::iterator iter;  
    iter = mirrorList.find(a);  
    if(iter!=mirrorList.end()){  
        if(b==iter->second)return true;  
        else return false;  
    }  
    else return false;  
}  
  
int main(){  
      
    string inp;  
    while(cin>>inp){  
        int n=inp.length();  
        bool pal=true, mir=true;  
        int arrow=0;  
        for(;arrow<n/2;arrow++){  
            char front=inp[arrow], back=inp[n-1-arrow];  
            if(front!=back)pal=false;  
            if(!mir || !checkmir(front, back))mir=false;  
        }  
        if(n%2)mir=checkmir(inp[arrow], inp[arrow]) && mir;  
        //cout<<arrow<<' '<<n;  
        if(mir && pal)cout<<inp<<" -- is a mirrored palindrome.\n";  
        if(!mir && pal)cout<<inp<<" -- is a regular palindrome.\n";  
        if(mir && !pal)cout<<inp<<" -- is a mirrored string.\n";  
        if(!mir && !pal)cout<<inp<<" -- is not a palindrome.\n";  
        inp[0]='\0';  
    }  
    return 0;  
}  