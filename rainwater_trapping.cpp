#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int rainWaterTrap(vector<int> v){
    int area = 0;
    int n = v.size();
    vector<pair<int,int>>a(n);
    a[0].first = v[0];
    int maxi = v[0];
    for(int i = 1 ; i < n ; i++){
        maxi = max(v[i] , maxi);
        a[i].first = maxi;
    }
    a[n-1].second = v[n-1];\
    maxi = v[n-1];
    for(int i = n - 2 ; i >= 0 ; i--){
        maxi = max(maxi ,v[i]);
        a[i].second = maxi;
    }

    for(int i = 0 ; i < n ; i++)
        area +=  min(a[i].first , a[i].second) - v[i];
    return area;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &i : v) cin>>i;
    cout<<rainWaterTrap(v);
    return 0;
}