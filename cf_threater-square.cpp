#include<iostream>
#include<cmath>
using namespace std;
int main(){
    unsigned long long int n,m;
    long double a;
    cin>>n>>m>>a;
    unsigned long long val = ceil(n/a)*ceil(m/a);
    cout<<val;
    return 0;
}