#include<iostream>
#include<vector>
using namespace std;
#define ll long long int

class matrix{
    private:
        vector<vector<ll>> mat;
        ll rows;
        ll cols;
    public:
        matrix(ll rows , ll cols , char type = '0'){
            this->rows = rows;
            this->cols = cols;
            vector<ll>temp(cols , 0);
            for(ll i = 0 ; i < rows ; i++)
                mat.push_back(temp);
            if(type == 'i'){
                try{
                    if(rows == cols){
                        for(ll i = 0 ; i < rows ; i++)
                            mat[i][i] = 1;
                    }
                    else throw "exception";
                }
                catch(...){
                    cout<<"Error: Identity matrix should me sqaure matrix.\n";
                }
            }
        }
    // modify matrix functions
        void set(ll val ,ll x , ll y);
        void set(ll **arr , ll rows , ll cols);
    // read matrix
        ll get(ll x , ll y);
        void print();

    // conditional operator overloading
        void operator = (matrix temp);
        bool operator== (matrix temp);
        bool operator > (matrix temp);
        bool operator < (matrix temp);
        bool operator >= (matrix temp);
        bool operator <= (matrix temp);
    
    // arithmetic operator overloading
        friend matrix operator+ (matrix a , matrix b);
        friend matrix operator- (matrix a , matrix b);
        friend matrix operator* (matrix a , matrix b);
        friend matrix operator/ (matrix a , matrix b);

    // Some build in functions
        friend matrix transpose();
        friend matrix adjoint();
        friend matrix inverse();
};

void matrix::print(){
    for(ll i = 0 ; i < rows ; i++){
        for(ll j = 0 ; j < cols ; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    matrix mat(5,5 , 'i');
    mat.print();
    return 0;
}