// link =  https://hack.codingblocks.com/app/practice/1/137/problem

#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
#define ll long long
#define lli unsigned long long int

void seive(vector<int>&primes){
    // ll n = 100000001;
    ll n = 10000;
    bool* arr = new bool[n];
    memset(arr , 0 , sizeof(arr));
    arr[0] = arr[1] = 1;

    for(ll i = 2 ; i <= n ; i++){
        if(arr[i] == 0){
            primes.push_back(i);
            cout<<i<<" ";
            for(lli j = i*i ; j <= n ; j += i){
                arr[j] = 1;
            }
        }
    }
    delete [] arr;
}

vector<pair<int,int>> factorise(ll k , const vector<int>& primes){
    int idx = 0;
    vector<pair<int,int>>v;
    while (k > 1){
        ll p = primes[idx];
        if(k%p == 0){
            int cnt = 0;
            while(k%p == 0){
                k = k/p;
                cnt++;
            }
            v.push_back({p,cnt});
        }
        idx++;
    }
    return v;
}

vector<pair<int,int>> solve(vector<pair<int,int>> &fact_k ,ll n){
    vector<pair<int,int>>v;
    for(auto it : fact_k){
        ll k = it.first;
        ll pow = k;
        ll count = 0;
        while(n/pow > 0){
            count += n/pow;
            pow *= k;
        }
        v.push_back({k,count});
    }
    return v;
}

int main(){
    vector<int>primes;
    seive(primes);
    int T;
    cin>>T;
    T = 0;
    while (T--){
        ll n , k;
        cin>>n>>k;
        vector<pair<int,int>> fact_k = factorise(k,primes);
        vector<pair<int,int>> fact_n = solve(fact_k , n);

        int size = fact_k.size();
        int mini = INT_MAX;
        for(int i = 0 ; i < size ; i++){
            mini = min(mini , fact_n[i].second/ fact_k[i].second);
        }
        cout<<mini<<"\n";
    }
    
    return 0;
}