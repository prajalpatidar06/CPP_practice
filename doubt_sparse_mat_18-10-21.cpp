#include<iostream>
using namespace std;

class element
{
    public:
    int i;
    int j;
    int x;
};

class sparse
{
    int m;
    int n;
    int num;
    struct element *ele;
    
    public:
    sparse(){}
    sparse(int m,int n,int num)
    {
        this->m=m;
        this->n=n;
        this->num=num;
        ele=new  element[this->num];
    }
    
    sparse operator+(sparse &s );
    friend istream& operator>>(istream &is, sparse &s );
    friend ostream& operator<<(ostream &os, sparse &s );
};


istream& operator>>(istream &is, sparse &s )
{
    cout<<"\row column element\n";
    for(int i=0;i<s.num;i++)
        is>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;

    return is;
}

ostream& operator<<(ostream &os, sparse &s )
{
    int k=0;

    for(int i=0;i<s.m;i++)
    {
        for(int j=0;j<s.n;j++)
        {
            
            if(i== s.ele[k].i && j== s.ele[k].j)
               os<<s.ele[k++].x<< "  ";
            else 
               os<<"0"<<"  ";
        }
        os<<endl;
    }
    return os;
}

sparse sparse :: operator+(sparse &s )
{
     
    if(m !=s.m || n !=s.n)
    {
        return sparse(0,0,0);
    }
    sparse *sum =new sparse(m,n,num+s.num);

    int i,j,k;
    i=j=k=0;

    while(i<num && j<s.num)
    {
        if(ele[i].i < s.ele[j].i)
           sum->ele[k++]=ele[i++];
        else if(ele[i].i > s.ele[j].i)
           sum->ele[k++]=s.ele[j++];
        else
        {
            if(ele[i].j > s.ele[j].j)
               sum->ele[k++]=s.ele[j++];
            else if(ele[i].j < s.ele[j].j)
               sum->ele[k++]=s.ele[i++];
            else
            {
                // sum.ele[k]=s1.ele[i].i; wrong
                // sum.ele[k]=s1.ele[i].j;
                sum->ele[k]=ele[i];      //right
                sum->ele[k++].x=ele[i++].x+s.ele[j++].x;
            }
        }
    }
    for(;i<num;i++)
        sum->ele[k++]=ele[i];
    for(;j<s.num;j++)
        sum->ele[k++]=s.ele[j];

    sum->m=m;
    sum->n=n;
    sum->num=k;

    return *sum;

}

int main()
{
    sparse s1(5,5,4),s2(5,5,5);

    cin>>s1;
    cin>>s2;

    sparse sum=s1+s2;

    cout<<"1st matrix"<<"\n"<<s1;
    cout<<"2nd matrix"<<"\n"<<s2;
    cout<<"sum matrix"<<"\n"<<sum;

return 0;
}