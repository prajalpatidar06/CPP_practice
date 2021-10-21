#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    double n = stod(s);
    for(int i = 0 ; i < 5 ; i++){
        if(n > 1)
            cout<<"full ";
        else if(n < 1 && n > 0){
            n = 0;
            cout<<"half ";
        }
        else
            cout<<"empty ";
        n -= 1;
    }
    return 0;
}