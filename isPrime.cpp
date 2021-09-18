#include<iostream>
#include<vector>
using namespace std;

vector<int> primeFinder(int n){
    vector<bool>num(n+1);
    fill(num.begin(),num.end(),0);
    vector<int>prime;
    for(int i = 2 ; i <= n ; i++){
        if(num[i] == 0){
            prime.push_back(i);
            for(int j = i*i ; j <= n ; j+=i)
                num[j] = 1;
        }
    }
    cout<<"\n";
    return prime;
}

int main(){
    int n;
    cin>>n;

    auto res = primeFinder(n);
    for(auto i : res){
        cout<<i<<" ";
    }
    return 0;
}