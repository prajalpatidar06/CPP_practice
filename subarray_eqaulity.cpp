#include <iostream>
#include<cstring>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        int *csl = new int[n];
        int *csr = new int[n];
        memset(csl,0,sizeof(csl));
        memset(csr,0,sizeof(csr));
        csl[0] = (arr[0]) ? 1 : -1;
        csl[n-1] = (arr[n-1]) ? 1 : -1;
        for(int i = 1 ; i < n ; i++){
            csl[i] = csl[0] + (arr[i]) ? 1 : -1;
            csr[n-1-i ] = csr[n-i] + (arr[n-1-i]) ? 1 : -1;
        }
        int k = 1;
        long long int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(csl[i] == 0){
                count += k;
                k++;
            }
        }
        for(int i = n-1 ; i >= 0 ; i--){
            if(csr[i] == 0){
                count += k;
                k++;
            }
        }
        delete [] csl;
        delete [] csr;
        return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends