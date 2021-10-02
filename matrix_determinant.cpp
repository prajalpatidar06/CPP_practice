#include<iostream>
#include<vector>
#include <algorithm>
#define ll long long
using namespace std;

ll det(vector<vector<ll>>B){
    int row_size = B.size();
    int col_size = B[0].size();

    if(row_size != col_size){
        cout<<"Dimmension Error\n";
        return 0;
    }
    if(row_size == 1)
        return B[0][0];
    if(row_size == 2)
        return B[1][1]*B[0][0]-B[1][0]*B[0][1];

    ll res = 0;
    for(int itr = 0 ; itr < col_size ; itr++){
        vector<vector<ll>>help;
        for(int i = 1 ; i < row_size ; i++){
            vector<ll>temp;
            for(int j = 0 ; j < col_size ; j++){
                if(j != itr)
                    temp.push_back(B[i][j]);
            }
            help.push_back(temp);
        }
        res += (itr&1) ? B[0][itr] * det(help) * (-1) : B[0][itr] * det(help); 
    }
    return res;
}


int main()
{
    int determinant;
    int row,col;
    cin>>row>>col;
    vector<vector<ll>>A(row, vector<ll>(col));
    for( auto &i : A)
        for(auto &j : i)
            cin>>j;

    determinant = det(A);
    cout<<determinant<<endl;

    return 0;
}