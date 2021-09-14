#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n == 1){
            cout<<-1<<" "<<-1<<"\n";
            continue;
        }
        bool check = false;
        for(int i = 0 ; i < n-1 ; i++){
            if(s[i] != s[i+1]){
                cout<<i+1<<" "<<i+2<<"\n";
                check = true;
                break;
            }
        }
        if(!check)
            cout<<-1<<" "<<-1<<"\n";

    }
    return 0;
}