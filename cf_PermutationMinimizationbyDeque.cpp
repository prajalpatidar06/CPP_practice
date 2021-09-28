// link: https://codeforces.com/contest/1579/problem/E1
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s = "";
        char inp;
        while(n--){
            cin>>inp;
            if(s == ""){
                s = inp;
                continue;
            }
            if(inp > s[0]){
                s = s + inp;
            }else{
                s = inp + s;
            }
        }
        
        for(auto i : s){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}