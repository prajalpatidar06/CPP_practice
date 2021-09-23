#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int xorr = 0;
        vector<int>v(n);
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
            xorr ^= v[i];
        }
        bool check = false;
        for(int i = 0 ; i < n ; i++){
            int a = xorr^v[i];
            if(a == v[i]){
                cout<<"YES\n";
                check = true;
                break;//11 21 20 1
            }
        }
        if(!check){
            cout<<"NO\n";
        }
    }
    return 0;
}