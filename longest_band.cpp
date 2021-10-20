#include<iostream>
#include<queue>
#include<climits>
#include<vector>
using namespace std;

int longestBand(vector<int>v){
    priority_queue<int,vector<int>,greater<int>>qt;
    for(auto i : v) qt.push(i);
    int maxi = 0;
    int last_ele = INT_MAX;
    int curr = 1;
    while (!qt.empty()){
        if(last_ele + 1 == qt.top()){
            curr++;
            last_ele++;
        }
        else{
            last_ele = qt.top();
            maxi = max(maxi , curr);
            curr = 1;
        }
        qt.pop();
    }
    return max(maxi , curr);  
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &i : v) cin>>i;
    cout<<longestBand(v);
    return 0;
}