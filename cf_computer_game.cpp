// link: https://codeforces.com/contest/1598/problem/A

#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string v1;
        string v2;
        cin>>v1;
        cin>>v2;
        bool done =false;
        for(int i = 0 ; i < n; i++){
            if(v1[i] == '1' && v2[i] == '1'){
                cout<<"No\n";
                done = true;
                break;
            }
        }
        if(!done){
            if(v1[0] == '1' || v2[n-1] == '1'){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }

    }
    return 0;
}