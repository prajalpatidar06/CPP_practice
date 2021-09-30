// link: https://codeforces.com/problemset/problem/112/A

#include<iostream>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    bool got = false;
    for(int i = 0 ; i < s1.size() ; i++){
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
        if(s1[i] > s2[i]){
            cout<<"1\n";
            got = true;
            break;
        }
        else if(s1[i] < s2[i]){
            cout<<"-1\n";
            got = true;
            break;
        }
    }
    if(!got){
        cout<<"0\n";
    }
    return 0;
}