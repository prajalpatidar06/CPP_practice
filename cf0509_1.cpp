#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s , r;
        cin>>s;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'U'){
                r += 'D';
            }else if(s[i] == 'D'){
                r += 'U';
            }
            else{
                r += s[i];
            }
        }
        cout<<r<<"\n";
    }
    return 0;
}