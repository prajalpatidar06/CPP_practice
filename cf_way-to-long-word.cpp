#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        int size = s.size();
        if(size > 10 ){
            s = s[0] + to_string(size-2) + s[size-1];
        }
        cout<<s<<"\n";
    }
    return 0;
}