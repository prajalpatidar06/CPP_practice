#include<iostream>
#include<vector>
#include <algorithm>
int n =  3;
int m =  3;
using namespace std;


int det(vector<vector<int>>B);

int main()
{
    int determinant;
    int row=3,col=3;
    vector<vector<int>>A(n , vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }

    determinant = det(A);

    cout<<determinant<<endl;

    return 0;
}

int det(int B[][2])
{
    int row_size = n;
    int col_size = m;

    if(row_size != col_size)
    {
        cout<<"Dimmension Error\n";
        exit(1);
    }
    else if(row_size == 1)
    {
        return B[0][0];
    }
    else if(row_size == 2)
    {
        return B[1][1]*B[0][0]-B[1][0]*B[0][1];
    }
    else{
        vector<vector<int>>help(row_size , vector<int>(col_size));
        int rowH,colH;
        int idx;
        int D=0;
        int i,j;
        for(idx =0; idx < row_size;idx++)
        {
            rowH=0;
            for(i= 1;i<row_size;i++)
            {
                colH=0;
                for(j=0;j<col_size;j++)
                {
                    if(j == idx)
                    {
                        continue;
                    }
                    else{
                        help[rowH][colH] = B[i][j];
                    }
                    colH++;
                }
                rowH++;
            }

            n = rowH;
            m = colH;

            if(idx%2 == 0)
            {
                D += B[0][idx]*det(help);
            }
            else{
                D -= B[0][idx]*det(help);
            }
        }
        return D;
    }

}