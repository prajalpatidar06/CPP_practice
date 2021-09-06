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
        matrix(ll rows , ll cols){
            this->rows = rows;
            this->cols = cols;
            vector<ll>temp(cols , 0);
            for(ll i = 0 ; i < rows ; i++){
                mat.push_back(temp);
            }
        }
    // modify matrix functions
        void set(ll val ,ll x , ll y);
        void set(ll **arr , ll rows , ll cols);
    // read matrix
        ll get(ll x , ll y);

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
    


};

int main(){
    matrix mat(5,5);

    return 0;
}