#include<iostream>
#include<cmath>
using namespace std;

bool palin(int& inp) {
    int count=0;
    int n = int(log10(inp))+1;
    // cout<<n<<endl;
    for (int i = 0; i < int(n/2); i++){
        int l =  inp/pow(10,n-1-2*i);
        int r = inp/pow(10, 1);
        r = inp - pow(10, 1)*r;

        if (l==r){
            count++;
        }
        else {
            return 0;
        }
        inp = (inp - (l*pow(10,n-1-2*i)))/10;
    }
    if (count==int(n/2)){
        return 1;
    }
}

int main() {
    int inp;
    cin>>inp;
    cout<<boolalpha<<palin(inp)<<endl;
    return 0;
}