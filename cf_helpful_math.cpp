// link: https://codeforces.com/problemset/problem/339/A

#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count1 = 0 , count2 = 0 , count3 = 0;
    for(auto i : s){
        if(i == '1')count1++;
        else if(i == '2')count2++;
        else if(i == '3')count3++;
    }
    if(count1--) cout<<"1";
    else if(count2--) cout<<"2";
    else if(count3--) cout<<"3";

    while(count1 > 0 || count2 > 0 || count3 > 0){
        if((count1--) > 0)cout<<"+1";
        else if((count2--) > 0)cout<<"+2";
        else if((count3--) > 0)cout<<"+3";
    }
    return 0;
}