// link: https://codeforces.com/problemset/problem/282/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int res = 0;
    string s;
    while (n--){
        cin>>s;
        if(s[0] == '+' || s[1] == '+' || s[2] == '+')
            res++;
        else
            res--;
    }
    cout<<res<<"\n";
    return 0;
}