// link: https://codeforces.com/contest/1598/problem/B
// wrong ans

#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,vector<int>>mp;
        int inp;
        for(int i = 0 ; i <n ; i++){
            for(int j = 1 ; j <= 5 ; j++){
                cin>>inp;
                if(inp == 1){
                    mp[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(auto i : mp){
            if(i.second.size() >= (n/2)){
                count++;
            }
        }
        if(count >= 2){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}