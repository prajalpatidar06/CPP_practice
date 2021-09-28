// (A * B)%m = 1 (where B is multiplicative modulo inverse)
// AB + 1 = m*k 
// AB + m(-k) = 1

#include<iostream>
using namespace std;

int gcd(int a , int& x , int b , int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
   int ans = gcd(b , x , a%b , y);
   int t = y;
   y = x - (a/b)*y;
   x = t;
    return ans;
}

int multiplicativeInverse(int a , int m){
    int x,y;
    gcd(a , x ,m ,y);
    return (x+m)%m;
}

int main(){
    cout<<multiplicativeInverse(18,7);
    return 0;
}