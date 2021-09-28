// constraints: n <= 10^7 , m<= 10^250
//  find m%n ?

#include<iostream>
using namespace std;

int gcd(int a , int b){
    return (b == 0) ? a : gcd(b , a%b);
}

int modulo(int n , string m){
    int res = 0;
    int pow = 1;
    for(int i = m.size() - 1 ; i >= 0 ; i--){
        int val = m[i] - '0';
        res = (res + val*pow)%n;
        pow = (pow*10)%n;
    }
    return gcd(n,res);
}

int main(){
    int n;
    string m;
    cin>>n>>m;
    cout<<modulo(n,m);
    return 0;
}