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
        int count = 0;
        for(int i = s.size()-1 ; i >= 0 ;i--){
            if(s[i] == '0')
                continue;
            int num = s[i] - '0';
            count += num;
            if(i != (s.size()-1)){
                count++;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}