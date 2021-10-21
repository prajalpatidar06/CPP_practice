// link: https://codeforces.com/problemset/problem/263/A

#include<iostream>
using namespace std;
int main(){
    bool inp;
    int seti , setj;
    for(int i = 1 ; i <= 5 ; i++){
        for(int j = 1 ; j <= 5 ; j++){
            cin>>inp;
            if(inp == 1){
                seti = i;
                setj = j;
            }
        }
    }
    cout<<(abs(3-seti) + abs(3 - setj));
    return 0;
}