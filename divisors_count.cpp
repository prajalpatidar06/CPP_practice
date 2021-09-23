#include<iostream>
#include<vector>
#include<cstring>
#define n 10000007
using namespace std;

void seive(vector<int>&primes){
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
    int t;
    cin>>t;
    vector<int>primes;
    seive(primes);
    while (t--){
        int q;
        cin>>q;

        long long ans = 1;
        int cnt;

        for(int i = 0 ; primes[i]*primes[i] <= q ; i++){
            cnt = 0;
            while (q % primes[i] == 0){
                cnt++;
                q = q/primes[i];
            }
            if(cnt){
                ans *= (cnt+1);
            }
        }
        if(q != 1){
            ans *= 2;
        }

        cout<<ans<<"\n";
    }
    
    return 0;
}