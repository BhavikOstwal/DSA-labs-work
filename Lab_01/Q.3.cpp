#include<iostream>
using namespace std;

int calculateArea(int length, int width){
    return length*width;
}

int calculatePerimeter(int length, int width){
    return 2*(length+width);
}

int main() {
    int a,b;
    cout<<"Enter the dimensions of the rectangle: "<<endl;
    cout<<"Length: ";
    cin>>a;
    cout<<"Width: ";
    cin>>b;
    cout<<"Area : "<<calculateArea(a,b)<<endl;
    cout<<"Perimeter : "<<calculatePerimeter(a,b)<<endl;
    return 0;
}