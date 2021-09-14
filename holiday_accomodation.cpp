#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>v;
    string s;
    while(n--){
        cin>>s;
        int si = s.size()/2;
        string res;
        for(int i = 0 ; i < si ;  i+=2){
            res += s[i];
        }
        v.push_back(res);
    }

    for(auto i : v){
        cout<<i<<"\n";
    }

    return 0;
}