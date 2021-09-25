#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    vector<int>v(n);
    for(auto &i : v){
        cin>>i;
    }
    cin>>k;
    sort(v.begin(),v.end(),greater<int>());
    int sum = 0;
    for(int i = 0 ; i < k ; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}