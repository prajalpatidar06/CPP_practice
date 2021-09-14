#include<iostream>
using namespace std;
int main(){
    string x;
    char seed;
    cin>>x>>seed;

    string y = "";
    char K = '\0';
    for(int i = 0 ; i < x.size() ; i++){
        // seed = (K == 0) ? seed : char((seed + K)%8);
        y += char(x[i] ^ seed) + '\0';
        // K = y[i];
    }
    cout<<y<<"\n";
    return 0;
}