// link = https://codeforces.com/problemset/problem/1294/C

#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

void seive(vector<int>&primes){
    int n = 100000;
    int *arr = new int[n];
    memset(arr,0,sizeof(arr));
    arr[0] = arr[1] = 1;
    for(int i = 2 ; i < n ; i++){
        if(arr[i] == 0){
            primes.push_back(i);
            for(unsigned long long int j = i*i ; j < n ; j += i){
                arr[i] = 1;
            }
        }
    }
    delete [] arr;
}
int main(){
    vector<int>primes;
    seive(primes);
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        long long Nt = N;
        vector<pair<long long, int>>factor;
        for(long long i = 0 ; primes[i]*primes[i] <= N ; i++){
            int p = primes[i];
            int cnt = 0;
            while(N%p == 0){
                N = N/p;
                cnt++;
            }
            if(cnt > 0){
                factor.push_back({p,cnt});
            }
        }
        if( N != 1){
            factor.push_back({N,1});
        }
        if(factor.size() >= 3){
            vector<long long>ans(3,1);
            int i = 0;
            for(auto itr : factor){
                unsigned long long int t = pow(itr.first ,itr.second);
                ans[i%3] *= itr.first;
                i++;
            }
            cout<<"YES\n"<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
        }
        else if(factor.size() == 2){
            long long a = factor[0].first;
            long long b = factor[1].first;
            long long c = Nt/(a*b);
            if(c != a && c != b && a > 1 && b > 1 && c > 1 && (a*b*c == Nt))
                cout<<"YES\n"<<a<<" "<<b<<" "<<c<<"\n";
            else
                cout<<"NO\n";
        }
        else{
            if(factor[0].second >= 6){
                long long a = factor[0].first;
                long long b = a*a;
                long long c = pow(a,factor[0].second-3);
                cout<<"YES\n"<<a<<" "<<b<<" "<<c<<"\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}