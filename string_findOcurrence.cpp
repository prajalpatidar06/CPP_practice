#include<iostream>
#include<string>
using namespace std;
int main(){
    string para = "WeSTL are learning about STL strings. STL strings is quite powerful and good tool for charecter array handeling";
    string s;
    getline(cin,s);
    int occr = 1;
    int x = -1;
    while(true){
        x = para.find(s,x+1);
        if(x != -1){
            cout<<occr++<<") "<<x<<"\n";
        }
        else{

            break;
        }
    }
    return 0;
}