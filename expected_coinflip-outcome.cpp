// what is the expected number of coin flips to get N consecutive heads?

#include<iostream>
#include<cmath>
using namespace std;

int expected_count(int val){
    int p = 1;
    return (p<<(val))-2;
}

int main(){
    int n;
    cin>>n;

    cout<<expected_count(n)<<"\n";
    return 0;
}