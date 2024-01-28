#include<iostream>
using namespace std;

int gcd(int a , int b){
    if (a%b==0){
        return b;
    }
    return gcd(b, a%b);
}

int main() {
    string a,b;
    do { 
        cout<<"Enter the first number(+ve): ";
        cin>>a;
    } while (stoi(a)<1 || stoi(a)!=stof(a));

    do { 
        cout<<"Enter the second number(+ve): ";
        cin>>b;
    } while (stoi(b)<1 || stoi(b)!=stof(b));
    cout<<gcd(max(stoi(a),stoi(b)),min(stoi(a),stoi(b)))<<endl;
    return 0;
}
