#include<iostream>
using namespace std;

class complex
{
    private:
    	int a,b;
    public:
		complex(){
			a = 0;
			b =0;
		}
    	complex(int x,int y)
    	{
    		a=x;
    		b=y;
		}
    	complex operator+(complex t)
    	{
    		complex temp;
    		temp.a=a+t.a;
    		temp.b=b+t.b;
    		return temp;
		}
		void display()
		{
			cout<<a<<"+i"<<b;
		}
};

int main()
{
	complex c1(5,6);
	complex c2(7,8);
	complex c = c1.operator+(c2);
    //c=c1+c2;	
    c.display();
return 0;
}