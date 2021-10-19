#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n , k;
    cin>>n;
    vector<int>v(n);
    vector<vector<int>>res;
    for(auto &i : v) cin>>i;
    cin>>k;
    sort(v.begin() , v.end());
    for(int i = 0 ; i < n ; i++){
        int sum = k - v[i];
        int l = i+1 , h = n-1;
        while (l < h){
            if(v[l] + v[h] == sum){
                res.push_back({v[i] , v[l] , v[h]});
                l++,h--;
            }
            else if(v[l]+v[h] > sum)
                h--;
            else l++;
        }
    }
    for(auto it : res){
        for(auto jt : it)
            cout<<jt<<" , ";
        cout<<"\n";
    }
    return 0;
}