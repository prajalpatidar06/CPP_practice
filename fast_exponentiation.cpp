#include<iostream>
using namespace std;

int power(int a , int b){
    if(!b)return 1;
    if(b == 1)return a;
    int res = power(a,(b>>1));
    if(b&1)
        return a*res*res;
    else
        return res*res;
}

int main()
{
    int a , b;
    cin>>a>>b;
    cout<<power(a,b);
 return 0;
}