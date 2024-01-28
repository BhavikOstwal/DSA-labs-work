#include<iostream>
#include<cmath>
using namespace std;

bool solid = false;

double calculateVolume(double radius, double height){
    return M_PI*pow(radius, 2)*height;
}

double calculateSurfaceArea(double radius, double height){
    if (solid){
        return 2*M_PI*radius*height + 2*M_PI*pow(radius,2);
    }
        return 2*M_PI*radius*height;
}

int main() {
    double r,h;
    cout<<"Enter the dimensions of the cylinder: "<<endl;
    cout<<"Radius: ";
    cin>>r;
    cout<< "Height: ";
    cin>>h;
    cout<<"Is it a solid cylinder? (true/false)\n";
    cin>>boolalpha>>solid;
    cout<<"Volume: "<<calculateVolume(r,h)<<endl;
    cout<<"Surface Area: "<<calculateSurfaceArea(r,h)<<endl;
    return 0;
}