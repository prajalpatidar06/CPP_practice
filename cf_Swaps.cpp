#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; 
        int *a = new int [n];
        int *b = new int [n];
        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin>>b[i];
        }
        int mini = b[0];
        int maxi = a[0];
        int maxi_idx = -1;
        int mini_idx = -1;
        for(int i = 0 ; i < n ; i++){
            if(a[i] < mini){
                mini_idx = i;
                break;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(b[i] > maxi){
                maxi_idx = i;
                break;
            }
        }
        cout<<min(mini_idx,maxi_idx)<<"\n";
        delete [] a;
        delete [] b;
    }
    return 0;
}