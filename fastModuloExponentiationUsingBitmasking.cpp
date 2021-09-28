#include<iostream>
using namespace std;
#define lli unsigned long long

lli expo(lli a , lli b , lli& m){
    lli res = 1;
    while(b > 0){
        if(b&1){
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b = b>>1;
    }
    return res;
}

int main(){
    lli a , b , m;
    cin>>a>>b>>m;
    cout<<expo(a,b,m);
    return 0;
}