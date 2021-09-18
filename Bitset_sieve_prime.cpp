#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

int n = 10000000;
bitset<10000005>b;
vector<int>v;

void seive(){
    b.set();
    b[0]=b[1] = 0;
    for(long long int i = 2 ; i <= n ; i++){
        if(b[i]){
            v.push_back(i);
            for(long long int j = i*i ; j <= n ; j += i){
                b[j] = 0;
            }
        }
    }
}

bool isprime(long long int val){
    if(val <= n){
        return (b[val] == 1) ? true : false;
    }
    for(long long int j = 0 ; v[j]*(long long)v[j] <= val ; j++){
        if(val%v[j] == 0){
            return false;
        }
    }
    return true;
}

int main(){
    seive();
    long long int t;
    cout<<"prime number checker\n";
    cout<<"input no = ";
    cin>>t;
    if(isprime(t) == true){
        cout<<"Prime Number\n";
    }else{
        cout<<"Number is not prime\n";
    }
    return 0;
}