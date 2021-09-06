#include<iostream>
#include<vector>
using namespace std;
#define vvi vector<vector<int>>

vvi matrix_transpose(vvi v){
    int n = v.size();
    int m = v[0].size();
    vvi t;
    for(int i = 0 ; i < m ; i++){
        vector<int>temp;
        for(int j = 0 ; j < n ; j++){
            temp.push_back(v[j][i]);
        }
        t.push_back(temp);
    }
    return t;
}

int main(){
    cout<<"Matrix Transpose Program\n";
    int n,m;
    cout<<"matrix dimension? : ";
    cin>>n>>m;
    vvi v(n);
    int input;
    cout<<"enter matrix : \n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>input;
            v[i].push_back(input);
        }
    }
    cout<<"Transpose of the matrix is : \n";
    vvi T  = matrix_transpose(v);
    for(int i = 0 ; i < T.size() ; i++){
        for(int j = 0 ; j < T[0].size() ; j++){
            cout<<T[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}