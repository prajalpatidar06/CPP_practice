#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(auto &i : v){
            cin>>i;
        }
        int idx = 0;
        while(k > 0 && idx < (n-1)){
            if(k > v[idx]){
                v[n-1] += v[idx];
                k = k - v[idx];
                v[idx] = 0;
                idx++;
            }else{
                v[idx] = v[idx] - k;
                v[n-1] += k;
                k = 0;
            }
        }
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}