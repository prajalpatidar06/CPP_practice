#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix_mult(vector<vector<int>> v1, int v1i, int v1j, vector<vector<int>> v2, int v2i, int v2j)
{
    vector<vector<int>> res;
    for (int i = 0; i < v1i; i++)
    {
        vector<int> t(v2j, 0);
        for (int j = 0; j < v2j; j++)
        {
            for (int k = 0; k < v1j; k++)
            {
                t[j] += v1[i][k] * v2[k][j];
            }
        }
        res.push_back(t);
    }
    return res;
}

vector<vector<int>> fast_expo(vector<vector<int>> v, int p)
{
    if(p == 0){
        return {{0,0},{0,0}};
    }
    if (p == 1)
    {
        return v;
    }
    vector<vector<int>> res = fast_expo(v, (p >> 1));
    if (p & 1)
    {
        return matrix_mult(v, 2, 2, matrix_mult(res, 2, 2, res, 2, 2), 2, 2);
    }
    else
    {
        return matrix_mult(res, 2, 2, res, 2, 2);
    }
}

int nth_fibo(int n)
{
    vector<vector<int>>mat;
    mat = {{0,1},{1,1}};
    vector<vector<int>>k = {{0},{1}};
    auto fast_ex = fast_expo(mat,n-2);
    auto res =matrix_mult(fast_ex,2 ,2,k,2,1);
    return res[1][0];
}

int main()
{
    int n = 3;
    cin>>n;
    int ans = 0;
    if(n == 1)
        ans = 0;
    if(n == 2)
        ans = 1;
    else if ( n > 2)
        ans = nth_fibo(n);

    cout<<n<<"th fibonacci number : "<<ans<<"\n";
    return 0;
}