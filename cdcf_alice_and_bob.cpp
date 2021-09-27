#include <iostream>
using namespace std;
#define lli unsigned long long int

int main() {
	// your code goes here
	long long t;
	// cin>>t;
    t = 1;
	while(t--){
	    lli n;
	    // cin>>n;
        n = 18;
	   
	   bool a = true;
	   while(n > 0){
	       if(n == 1){
	           if (a)cout<<"Alice\n";
	           else cout<<"Bob\n";
	           break;
	       }
	       if(n&1 == 1){
	           n--;
	           a = !(a);
	       }else{
	           while((n%2 == 0) && n > 0){
	               n = n>>1;
	               cout<<n<<" ";
	           }
	           a = !(a);
	       }
	   }
	}
	return 0;
}
