#include<iostream>
using namespace std;

void menu(){
    cout<<"1. Area of square\n";
    cout<<"2. Area of rectangle\n";
    cout<<"3. Area of circle\n";
    cout<<"4. Area of Equilateral triangle\n";
    cout<<"Enter your choice\n";
}

int main(){
    int n;
    menu();
    cin>>n;
    double a,b;
    switch (n){
        case 1:
            cout<<"Enter the side of square: ";
            cin>>a;
            cout<<"The area of square is "<<a*a<<"\n";
            break;
        case 2:
            cout<<"Enter the length and breadth of the rectangle: ";
            cin>>a>>b;
            cout<<"The area is "<<a*b<<"\n";
            break;
        case 3:
            cout<<"Enter the  radius of the circle: ";
            cin>>a;
            cout<<"The area is "<<a*a*(3.14)<<"\n";
            break;
        case 4:
            cout<<"Enter the side of triangle: ";
            cin>>a;
            cout<<"The area is "<<(1.73/4)*a*a<<"\n";
            break;
        default:
            cout<<"Error! Wrong choice entered\n";
    }
    return 0;
}