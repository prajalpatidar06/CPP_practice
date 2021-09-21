#include<iostream>
using namespace std;

void generate(int n){
    int i = n;
    if(i == 1){
        cout<<"()\n";
        return;
    }
    string s = "";
    for(int i = 0 ; i < n ; i++){
        s += "()";
    }
    string res;
    int j = 1;
    cout<<s<<"\n";
    i--;
    while(i--){
        res = s;
        char ch = res[j];
        res[j] = res[j+1];
        res[j+1] = ch;
        j +=2;
        cout<<res<<"\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        generate(n);
    }
    return 0;
}