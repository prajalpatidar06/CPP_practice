#include<iostream>
using namespace std;

class stack{
    private:
        int *st;
        int size;
        int count;
    public:
        stack(int size){
            st = new int[size];
            count = 0;
        }

        void push(int val){
            try{
                if(count < size){
                    st[count] = val;
                    count++;
                }
                else throw "exception";
            }
            catch(...){
                cout<<"Error: Stack Overflow\n";
            }
        }

        int pop(){
            try{
                if(count > 0){
                    count--;
                    return st[count];
                }
                else throw "exception";
            }
            catch(...){
                cout<<"Error: Stack Underflow\n";
            }
            return -1;
        }

        int peek(int index){
              try{
                if(index < count && index > 0){
                    return st[count - index];
                }
                else throw "exception";
            }
            catch(...){
                cout<<"Error: inaccessible memory location\n";
            }
            return -1;
        }

        void display(){
            for(int i = count-1 ; i >= 0 ; i--){
                cout<<st[i]<<" ";
            }
        }

};

int main(){
    cout<<"define size of stack: ";
    int size;
    cin>>size;
    stack st(size);
    bool loop = true;
    while(loop){
        cout<<"---------------------------------------------\n";
        cout<<"1. push() , 2. pop() , 3. peek() , 4. display()\n";
        cout<<"for exit press any other key\n";
        cout<<"---------------------------------------------\n";
        int input;
        cin>>input;
        switch (input)
        {
        case 1:
            cout<<"enter value to push: ";
            int val;
            cin>>val;
            st.push(val);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            cout<<"enter index to peek: ";
            int idx;
            cin>>idx;
            cout<<"element at index "<<idx<<" is "<<st.peek(idx)<<"\n";
            break;
        case 4:
            cout<<"stack elements : ";
            st.display();
            cout<<"\n";
            break;
        default:
            loop = false;
        }
    }
    cout<<"Thankyou , have a great day...\n";
    return 0;
}