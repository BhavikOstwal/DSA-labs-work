#include<iostream>
using namespace std;

int main() {
    string inp, a;
    cout<<"Enter the string: "<<endl;
    // cin>>inp;
    getline(cin, inp);
    a=inp;
    cout<<"Input string: "<<a<<endl;
    int count = 0; bool palin = false;
    int n = a.length();
    for (int i = 0; i < n/2; i++){   
        if (a.at(i) == a.at(n-i-1))
        {
            count++;
        }
        if (count==n/2)
        {
            palin = true;
        }
        char tmp = a.at(i);
        a.at(i) = a.at(n-i-1);
        a.at(n-i-1) = tmp;
    }
    cout<<"Reversed string: "<<a<<endl;
    if (inp==a)
    {
        palin=true;
    }
    cout<<"Is it Palindrome?: "<<boolalpha<<palin<<endl;
    cout<<n<<endl;
    return 0;
}