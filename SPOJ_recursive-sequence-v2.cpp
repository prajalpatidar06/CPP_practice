#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define vvl vector<vector<ll>>
#define vl vector<ll>

ll mod = 1;

vvl mult(vvl v1 , vvl v2){
    vvl res;
    ll size = v1.size(); 
    for(ll i = 0 ; i < size ; i++){
        vl t(size);
        for(ll j = 0 ; j < size ; j++){
            for(ll x = 0 ; x < size ; x++){
                t[j] = (t[j] + (v1[i][x]*v2[x][j])%mod)%mod;
            }
        }
        res.push_back(t);
    }
    return res;
}

vvl pow(vvl t , int n){
    if(n == 1){
        return t;
    }
    vvl res = pow(t , (n>>1));
    if(n&1)
        return mult(t , mult(res,res));
    else
        return mult(res,res);
}

ll compute(vl b, vl c, ll k, ll m, ll n, ll p)
{
    vvl t(k + 1, vl(k + 1));
    for (ll i = 0; i <= k; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            if (i == 0 || i == k)
            {
                t[i][j] = (!j) ? 1 : c[j - 1];
            }
            else
            {
                t[i][j] = (j == i + 1) ? 1 : 0;
            }
        }
    }

    vvl expo_n = pow(t, n);
    vvl expo_m = pow(t, m);
    
    ll Sn = 0;
    ll Sm = 0;
    for(ll i = 0 ; i <= k ; i++){
        cout<<expo_n[0][i]<<" ";
        Sn = (Sn + expo_n[0][i])%p;
        Sm = (Sm + expo_m[0][i])%p;
    }
    cout<<"\n";
    return (Sn-Sm);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll k, m, n, p;
        cin >> k;
        vl b(k);
        vl c(k);
        for (ll i = 0; i < k; i++)
        {
            cin >> b[i];
        }
        for (ll i = 0; i < k; i++)
        {
            cin >> c[i];
        }
        cin >> m >> n >> p;
        mod = p;
        cout<<compute(b, c, k, m, n, p)<<"\n";
    }
    return 0;
}