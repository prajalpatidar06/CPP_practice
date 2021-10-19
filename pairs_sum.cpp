#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void sort(vector<int> &v , int l , int h){
    if(l >= h)return;
    int mid = (l+h)/2;
    sort(v,l,mid);
    sort(v,mid+1,h);
    int i = l , j = mid+1 , k = 0;
    vector<int>b(h-l+1);
    while(i <= mid && j <= h){
        b[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
    }
    while(i <= mid){
        b[k++] = v[i++];
    }
    while(j <= h ){
        b[k++] = v[j++];
    }
    i = 0;
    for(j = l ; j <= h ; j++){
        v[j]  = b[i++];
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &i : v){
        cin>>i;
    }
    int k;
    cin>>k;

    // Brute force opproch ---time = O(n*n)
    // for(int i = 0; i < n ; i++){
    //     for(int j = i+1 ; j < n ; j++){
    //         if(v[i] + v[j] == k){
    //             cout<<v[i]<<","<<v[j]<<"\n";
    //             break;
    //         }
    //     }
    // }

    // using sorting time = O(n*log(n) + n)
    //     sort(v,0,n-1);
    //     int l = 0 , h = n-1;
    //     while(l < h){
    //         if(v[l]+v[h] == k){
    //             cout<<v[l]<<" , "<<v[h];
    //             break;
    //         }
    //         if(v[l]+v[h] > k){
    //             h--;
    //         }
    //         else{
    //             l++;
    //         }
    //     }

    // using Unordered_Set time = O(n)
    unordered_set<int>st;
    for(int i = 0 ; i < n ; i++){
        auto p = st.find(k - v[i]);
        if(p != st.end()){
            cout<<v[i] <<" , "<<*p<<"\n";
            break;
        }
        st.insert(v[i]);
    }
    return 0;
}