#include<iostream>
#include<string>
using namespace std;

void space20(string &s){
    int spaceCnt = 0;
    int n = s.size();
    for(int i = 0 ; i < n ; i++){
        if(s[i] == ' ')spaceCnt++;
    }
    s.append(' ', spaceCnt*2);
    int i = n-1,j = n+(spaceCnt*2);
    s[j--] = '\0';
    while(i >= 0 && j >= 0){
        if(s[i] == ' '){
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
            i--;
        }
        else{
            s[j--] = s[i--];
        }
    }
}

int main(){
    string s;
    getline(cin,s);
    cout<<s.size()<<"\n";
    space20(s);
    cout<<s<<"\n";
    cout<<s.size()<<"\n";
    return 0;
}