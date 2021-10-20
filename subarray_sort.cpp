#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool outOfOrder(vector<int> v , int i){
    if(i == 0)
        return v[i] > v[i+1];
    if(i == v.size()-1)
        return v[i] < v[i-1];
    return v[i] < v[i-1] || v[i] > v[i+1];
}

pair<int,int> subarraySort(vector<int>v){
    int minele = INT_MAX;
    int maxele = INT_MIN;
    int n = v.size();
    for(int i = 0 ; i < n ; i++){
       if(outOfOrder(v,i)){
           minele = min(v[i] , minele);
           maxele = max(v[i] , maxele);
       }
    }
    pair<int,int> ans = {-1,-1};
    for(int i = 0 ; i < n; i++){
        if(minele < v[i]){
            ans.first = i;
            break;
        }
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        if(v[i] < maxele){
            ans.second = i;
            break;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &i : v) cin>>i;
    auto idx = subarraySort(v);
    cout<<idx.first<<" , "<<idx.second;
    return 0;
}