#include<iostream>
#include<vector>
using namespace std;
#define ll unsigned long long int

void primeFinder(int n , vector<bool>num , vector<int>&primes){
   
}

int main(){
    int n;
    cin>>n;
    int maxi = 1000000+1;
	int *num = new int[maxi];
    fill(num,num+maxi,0);
	vector<int>primes;
     for(int i = 2 ; i <= maxi ; i++){
        if(num[i] == 0){
            primes.push_back(i);
            for(ll j = i*i ; j <= maxi ; j+=i)
                num[j] = 1;
        }
    }
   	while(n--){
		int a, b;
		cin>>a>>b;
		auto l = lower_bound(primes.begin(),primes.end(),a);
		auto r = lower_bound(primes.begin(),primes.end(),b);
		cout<<(r-l)<<"\n";
   }
    return 0;
}