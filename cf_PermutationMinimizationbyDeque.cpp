// link: https://codeforces.com/contest/1579/problem/E1
#include<iostream>
#include<deque>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
       deque<int>s;
        int inp;
        while(n--){
            cin>>inp;
            if(s.empty()){
                s.push_back(inp);
                continue;
            }
            if(inp > s.front()){
                s.push_back(inp);
            }else{
                s.push_front(inp);
            }
        }
        
        for(auto i : s){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}