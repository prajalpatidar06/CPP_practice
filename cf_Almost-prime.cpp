#include<iostream>
using namespace std;
int n = 3000;
int arr[3005] = {0};

void solve(){
    arr[0] = arr[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        if(!arr[i]){
            for(int j = i*2 ; j <= n ; j+= i){
                arr[j]++;
            }
        }
    }
    return;
}

int main(){
    int val;
    cin>>val;
    solve();
    int count = 0;
    for(int i = 1 ; i <= val ; i++){
        if(arr[i] == 2){
            count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}