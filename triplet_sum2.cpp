#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int>> triplet_sum(vector<int> v, int n, int target){
    vector<vector<int>>ans;
    sort(v.begin(),v.end());
    int sum,k,l,temp;
    for (int i = 0; i < n-3; i++){
        sum = target - v[i];
        temp=0;
        k = i+1,l=n-1;
        while(k < l){
            temp = v[k]+v[l];
            if(temp == sum){
                ans.push_back({v[i],v[k],v[l]});
                k++;
                l--;
            }
            else if(temp > sum){

                l--;
            }
            else{
                k++;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int &i : v){
        cin >> i;
    }
    int target;
    cin >> target;
    auto ans = triplet_sum(v, n , target);
    for(auto i : ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}