#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define ll unsigned long long int
#define lli unsigned long long int
int main(){
    ll t;
    cin>>t;
    vector<ll>heros(t);
    lli sum = 0;
    for(auto &i : heros){
        cin>>i;
        sum += i;
    }
    sort(heros.begin(),heros.end());
    ll m;
    cin>>m;
    while(m--){
        ll x ;
        lli y;
        cin>>x>>y;
        ll def = 0;
        if(x < heros[0]){
           def = heros[0];
        }else if(x > heros[t-1]){
            def = heros[t-1];
        }
        else{
            auto pd = lower_bound(heros.begin(),heros.end(),x) - heros.begin();
            def = (heros[pd] > x) ? heros[pd-1] : heros[pd];
        }
        lli coins = (def >= x) ? 0 : (x - def);
        lli temp = sum - def;
        coins = (temp >= y) ? coins : (coins + y - temp);
        cout<<coins<<"\n";
    }
    return 0;
}