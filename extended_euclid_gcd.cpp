//  Ax + By = gcd(A,B) , then find x and y which satisfied equation

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

int main(){
    int a , b  , x ,y;
    cin>>a>>b; 
    gcd(a,x,b,y);
    cout<<x<<" "<<y<<"\n";
    return 0;
}