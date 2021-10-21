#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int minSwaps(vector<int> v){
    vector<int>v2 = v;
    sort(v2.begin() , v2.end());
    int swaps = 0;
    int cnt = 0;
    unordered_set<int>st;
    for(int i = 0 ; i < v.size() ; i++){
        cnt = 0;
        if(st.find(v[i]) == st.end()){
            int t = i;
            while (st.find(v[t]) == st.end()){
                cnt++;
                st.insert(v[t]);
                t = lower_bound(v2.begin() , v2.end() , v[t]) - v2.begin();
            }
            swaps += cnt - 1;
        }
    }
    return swaps;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &i : v) cin>>i;
    cout<<minSwaps(v);
    return 0;
}