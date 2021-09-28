// link: https://codeforces.com/contest/1579/problem/0

#include<iostream>
using namespace std;

bool checker(char a , char b ){
    switch (a){
        case 'A':
            return (b == 'B');
            break;
        case 'B':
            return (b != 'B');
            break;
        case 'C':
            return (b == 'B');
            break;
        }
    return 0;
}

bool solve(string &s){
    if(s.size() == 1){
        return 0;
    }
    if(s.size() == 2){
       return checker(s[0],s[1]);
    }
    int j = s.size()-1;
    while(j > 1){
        if(checker(s[0],s[j])){
            s =  s.substr(1,j-1) + s.substr(j+1,s.size());
            return solve(s);
        }
        j--;
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool ans = solve(s);
        if(ans){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }

    }
    return 0;
}