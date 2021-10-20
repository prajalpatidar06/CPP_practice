#include<iostream>
#include<vector>
using namespace std;

int biggestMountain(vector<int>v , int n){
    int maxi = 0;
    int ground = 0;
    int curr = 0;
    bool findPeak = 0;
    for(int i = 1 ; i < n-1 ; i++){
        if(v[i] > v[i-1] && v[i] > v[i+1]){
            findPeak = true;
        }
        if(v[i] <= v[i-1] && v[i] <= v[i+1]){
            if(findPeak)
                maxi = max(maxi , i - ground + 1);
            findPeak = false;
            ground = i;
        }
    }
    if(findPeak){
        maxi = max(maxi , n-ground);
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &i : v)
        cin>>i;
    int ans = biggestMountain(v,n);
    cout<<ans;
    return 0;
}