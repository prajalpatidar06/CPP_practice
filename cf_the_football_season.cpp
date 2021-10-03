// link: https://codeforces.com/problemset/problem/1244/C

#include<iostream>
using namespace std;
#define ll long long

ll gcd(ll a , ll &x ,  ll b , ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll ans = gcd(b, x , a%b , y);
    ll tmp = y;
    y = x - (a/b)*y;
    x = tmp;
    return ans;
}

ll modeInverse(ll a , ll m){
    ll x , y;
    gcd(a,x,m,y);
    return (m + x)%m;
}

int main(){
    ll n , p , w, d;
    cin>>n>>p>>w>>d;
    ll tx , ty;
    ll x , y , z;
    ll g =  gcd(w , tx , d , ty);

    if(p%g != 0){
        cout<<"-1\n";
        return 0;
    }
    if(n*w < p){
        cout<<"-1\n";
        return 0;
    }
    p /= g; d /=g , w /= g;

    y = ((p%w) * modeInverse(d,w))%w;
    x = (p - (y*d))/w;
    if((x+y) > n){
        cout<<"-1\n";
        return 0;
    }
    if(x < 0){
        cout<<-1<<"\n";
        return 0;
    }
    z = n - x - y;
    cout<<x<<" "<<y<<" "<<z<<"\n";
    return 0;
}