#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int dp[1000006];
int arr[1000006];

int main(){
    int n;
    cin>>n;
    memset(arr, 0, n+1);
    memset(dp, 0, n+1);
    int input;
    double sum = 0.0;
    for(int i = 1 ; i <= n ; i++){
        cin>>input;
        dp[i] = dp[i-1] + i - arr[input];
        arr[input] = i;
        sum += dp[i];
    }

    double res = 0.0;
    res = (2*(sum-n)+n)/(n*n*1.0);
    cout<<fixed<<setprecision(9)<<res<<"\n";
    return 0;
}