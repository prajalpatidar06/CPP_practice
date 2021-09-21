#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int xorr = 0;
        int inp;
        for(int i = 0 ; i < n ; i++){
            cin>>inp;
            if(i == (n-1)){
                if(xorr == inp)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }else{
                xorr ^= inp;
            }
        }
    }
    return 0;
}