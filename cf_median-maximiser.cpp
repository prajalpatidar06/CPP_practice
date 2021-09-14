#include<iostream>
#include<cmath>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, s;
        cin>>n>>s;
        if(n == 1){
            cout<<s<<"\n";
            continue;
        }
        ll box = ceil((n+1)/(2*1.0));
        cout<<floor(s/box)<<"\n";
    }
    return 0;
}