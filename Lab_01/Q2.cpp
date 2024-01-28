#include<iostream>
using namespace std;

int recursFunc(int n){
    if (n<2){
        return 1;
    }
    return recursFunc(n-1)+ recursFunc(n-2);
}

void generateFibonacci(int n){
    for (int i = 0; i < n; i++)
    {
        cout<<recursFunc(i)<<" ";
    }
    cout<<endl;
}


int main() {
    float n;
    do { 
        cout<<"Enter a positive integer: ";
        cin>>n;
    }while (int(n)<1 || int(n)!= n);
    generateFibonacci(n);    
    return 0;
}