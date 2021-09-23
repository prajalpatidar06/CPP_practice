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

        for(int i = 0 ; primes[i]*primes[i] <= q ; i++){
            while (q % primes[i] == 0){
                q = q/primes[i];
                cout<<primes[i]<<" ";
            }
        }

        if(q != 1){
            cout<<q<<"\n";
        }

    }
    
    return 0;
}