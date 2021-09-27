// link: https://codeforces.com/problemset/problem/158/A

#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int count = 0;
    int inp;
    int last = 0;
    while(n--){
        cin>>inp;
        if(inp <= 0)continue;
        if(k > 0 || last == inp){
            count++;
            last = inp;
        }
        k--;
    }
    cout<<count<<"\n";
    return 0;
}