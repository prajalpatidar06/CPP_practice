#include<iostream>
#include<vector>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<ll>p(n+1,0);
        p[0] = 1;
        ll sum = 0;
        ll input;
        for(int i = 0 ; i < n ; i++){
            cin>>input;
            sum += input;
            sum %= n;
            sum = (sum+n)%n;
            p[sum]++;
        }
        ll ans = 0;
        for(int i = 0 ; i < n ; i++){
            ll m = p[i];
            ans += ((m)*(m-1))/2;
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}